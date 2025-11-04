#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        size_t farthestReachable = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (i > farthestReachable) return false;
            farthestReachable = max(farthestReachable, i + (size_t) nums[i]);
        }
        return true; // i reached last index
    }
};