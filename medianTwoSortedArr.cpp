#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // worse than log time
        // ironically leetcode says this was a 99th percentile solution
        vector<int> nums3 = vector<int>();

        // zip vectors together in non-decreasing order
        int i = 0;
        int j = 0;
        for (;;) {
            if (i >= nums1.size() && j >= nums2.size()) break;

            int val1 = INT_MAX;
            int val2 = INT_MAX;

            if (i < nums1.size()) val1 = nums1[i];
            if (j < nums2.size()) val2 = nums2[j];

            if (val1 <= val2) {
                nums3.emplace_back(val1);
                i++;
            } else {
                nums3.emplace_back(val2);
                j++;
            }
        }

        // now find median of of nums3
        if (nums3.size() % 2 == 1) { // odd length nums3
            int middle = nums3.size() / 2;
            return (double) nums3[middle];
        } else {
            int lower = (nums3.size() / 2) - 1;
            int upper = (nums3.size() / 2);
            return double(nums3[lower] + nums3[upper]) / 2.0;
        }
    }
};
