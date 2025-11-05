#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) left++;
                else if (sum > 0) right--;
                else {
                    // sum is 0
                    vector<int> entry = { nums[i], nums[left], nums[right] };
                    ans.emplace_back(entry);

                    // skip over duplicates
                    while (left < right && nums[left] == nums[left + 1]) left++; // left reaches last duplicate value
                    while (left < right && nums[right] == nums[right - 1]) right--; // right reaches last duplicate value

                    // push left and right one more place to get past all duplicates
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
};