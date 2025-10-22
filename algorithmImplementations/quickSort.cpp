#include<vector>
#include<iostream>
using namespace std;
void quickSort(vector<int>& nums, int left, int right) {
    if (right - left <= 0) return;

    int pivot = nums[right];
    int j = left - 1;
    for (int i = left; i < right; i++) {
        if (nums[i] <= pivot) {
            j++;
            // swap elements i and j
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        } // else do nothing
    }
    // swap pivot into place
    int temp = nums[j + 1];
    nums[j + 1] = pivot;
    nums[right] = temp;
    
    quickSort(nums, left, j);
    quickSort(nums, j + 1, right);
}

int main() {
    vector<int> nums = {1, 4, 2, 5, 34, 5};
    quickSort(nums, 0, nums.size() - 1);
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
}
