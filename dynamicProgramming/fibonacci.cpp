#include<vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        vector<int> memos(n + 1, -1);
        return fibHelper(n, memos);
    }

    int fibHelper(int n, vector<int>& memos) {
        if (n == 1) return 1;
        if (n == 0) return 0;

        if (memos[n] != -1) {
            return memos[n];
        }

        int ans = fibHelper(n - 1, memos) + fibHelper(n - 2, memos);
        memos[n] = ans;
        return ans;
    }
};