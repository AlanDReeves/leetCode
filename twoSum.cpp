#include<utility>
# include<vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<std::pair<int, int>> seen = std::vector<std::pair<int, int>>();
        for (int i = 0; i < int(nums.size()); i++) {
            seen.emplace_back(std::pair<int, int>({nums[i], i}));
            if (seen.size() == 1) {
                continue;
            }
            for (int j = 0; j < int(seen.size()); j++) {
                if (nums[i] + seen[j].first == target && seen[j].second != i) {
                    std::vector<int> ans = {i, seen[j].second};
                    return ans;
                }
            }
        }
        std::vector<int> garbage = {-1, -1}; // return garbage answer if no real answer found
        return garbage;
    }
};