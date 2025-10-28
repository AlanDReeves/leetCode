#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // area = (index2 - index1) * min(height[index1], height[index2])
        int maxArea = 0;
        size_t i = 0, j = height.size() - 1;
        while (i < j) {
            int minHeight = min(height[i], height[j]);
            int newArea = (j - i) * minHeight;
            maxArea = max(maxArea, newArea);

            if (minHeight == height[i]) i++;
            else j--;
        }
        return maxArea;
    }
};