#include<vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans = vector<int>();
        vector<int> memos(n + 1, -1);
        for (int i = 0; i <= n; i++) {
            ans.emplace_back(countForGiven(i, memos));
        }
        return ans;
    }

    int countForGiven(int n, vector<int>& memos) {
        int original = n;
        if (memos[n] != -1) return memos[n];

        int ones = 0;
        while (n > 0) {
            if (n % 2) ones++;
            n /= 2;
        }
        memos[original] = ones;
        return ones;
    }
};