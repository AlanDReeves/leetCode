#include<vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> memos (n + 1, 0); // make n sized vector with all 0s
        return countHelper(n, 0, memos);
    }

    int countHelper(int n, int sum, vector<int>& memos) {
        if (n == 0) return 1; // base case
        if (n < 0) return 0; // indicates not possible

        if (memos[n] != 0) return memos[n];
        // return early if answer found for this size

        int oneStep = countHelper(n - 1, sum, memos);
        int twoStep = countHelper(n - 2, sum, memos);

        sum += oneStep;
        sum += twoStep;

        memos[n] = sum; // record answer for this size

        return sum;
    }
};