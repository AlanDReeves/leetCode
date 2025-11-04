#include<vector>
#include<limits.h>
#include<queue>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
// initial solution. Much too slow due to linear search for smallest node
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         ListNode *head, *tail, *nextAdd;

//         head = getSmallestNode(lists);
//         if (!head) return nullptr;

//         tail = head;

//         for(;;) {
//             // determine which node comes next in order
//             nextAdd = getSmallestNode(lists);
//             if (!nextAdd) break;

//             // make the tail of the combined list point to next node
//             tail->next = nextAdd;

//             tail = nextAdd;
//         } 
//         return head;
//     }

//     ListNode* getSmallestNode(vector<ListNode*>& lists) {
//         // finds smallest value head in lists. Returns nullptr if no values are left
//         int least = INT_MAX;
//         int minindex = -1;
//         for (int i = 0; i < lists.size(); i++) {
//             if (lists[i] && lists[i]->val < least) {
//                 least = lists[i]->val;
//                 minindex = i;
//             }
//         }
//         if (minindex == -1) return nullptr;
//         ListNode* node = lists[minindex];
//         lists[minindex] = lists[minindex]->next; // advance the list HERE
//         return node;
//     }
// };

class Solution {
public:
    struct Compare {
        // functor struct for use with heap
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // create queue using Compare struct and push all head nodes
        priority_queue<ListNode*, vector<ListNode*>, Compare> pQueue;
        for (ListNode* node : lists) if (node) pQueue.push(node);

        ListNode placeHolder;
        ListNode* tail = &placeHolder;

        while (!pQueue.empty()) {
            ListNode* current = pQueue.top();
            pQueue.pop();

            tail->next = current;
            tail = current;
            if (current->next) pQueue.push(current->next);
        }

        return placeHolder.next;
    }
};