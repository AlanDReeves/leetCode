#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> memos(prices.size(), -1);

        return profitHelper(prices, 0, memos);
    }

    int profitHelper(vector<int>& prices, int index, vector<int>& memos) {
        if (index >= prices.size()) return 0; // no profit in 0 days

        if (memos[index] != -1) return memos[index];

        // find best profit if I buy today
        int priceToday = prices[index];
        int best = 0;
        for (size_t i = index; i < prices.size(); i++) {
            best = max(best, (prices[i] - priceToday));
        }

        best =  max(best, profitHelper(prices, index + 1, memos));
        memos[index] = best;
        return best;
        // compare to buying at some point in the future
    }
};

