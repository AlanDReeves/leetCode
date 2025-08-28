
 // Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = nullptr;
        ListNode *cursor = nullptr;
        while(l1 != nullptr || l2 != nullptr) {
            int num1 = 0;
            int num2 = 0;
            if (l1 != nullptr) {
                num1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                num2 = l2->val;
                l2 = l2->next;
            }
            // calculate sum, include previous carry
            int sum = num1 + num2 + carry;
            // if greater than 9, use carry
            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            // create node struct
            ListNode *nextNode = new ListNode(sum, nullptr);
            // add to list
            if (head == nullptr) {
                head = nextNode;
                cursor = head;
            } else {
                cursor->next = nextNode;
                cursor = cursor->next;
            }
        }
        if (carry > 0) {
            ListNode *finalNode = new ListNode(carry, nullptr);
            cursor->next = finalNode;
        }
        return head;
    }
};