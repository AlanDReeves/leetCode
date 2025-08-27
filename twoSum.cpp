#include<utility>
# include<vector>

class Solution {
    // Doesn't work yet. Currently always reaches return garbage
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<std::pair<int, int>> seen = std::vector<std::pair<int, int>>();
        for (int i = 0; i < int(nums.size()); i++) {
            for (int j = 0; j < int(seen.size()); j++) {
                if (nums[i] - seen[j].first == target) {
                    std::vector<int> ans = {i, seen[j].second};
                    return ans;
                }
                seen.emplace_back(std::pair<int, int>({nums[i], i}));
            }
        }
        std::vector<int> garbage = {-1, -1}; // return garbage answer if no real answer found
        return garbage;
    }
};