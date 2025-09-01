#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // just make a new array and write over the old one when finished
        // bad for memory, but good for time

        int i = 0;
        int j = 0;
        vector<int> newVec;

        while (i < int(nums1.size())) {
            int smallest;
            if (j < n) { // avoid index out of bounds
                smallest = customMin(nums1[i], nums2[j], i, m);
            }
            else {
                smallest = nums1[i];
            }
            newVec.emplace_back(smallest);
            if (j < n) {
                if (smallest == nums2[j]) {
                    j++;
                } 
                else if (smallest == nums1[i]) {
                    i++;
                }
            } else {
                i++;
            }
        }

        for (int i = 0; i < int(nums1.size()); i++) {
            nums1[i] = newVec[i];
        }
    }

    int customMin(int num1, int num2, int i, int m) {
        // when i < m, do normal min calculation
        if (i < m) {
            return min(num1, num2);
        }
        else { // when i >= m ignore num1
            return num2;
        }
    }
};