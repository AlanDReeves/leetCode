#include<vector>
#include<iostream>

using namespace std;

int binarySearch(vector<int>& nums, int target, int left, int right) {
    int middle = left + ((right - left) / 2);
    if (nums[middle] == target) return middle;

    if (left >= right) return -1; // ran out of search area without finding value

    if (nums[middle] > target) {
        return binarySearch(nums, target, left, middle - 1);
    }
    return binarySearch(nums, target, middle + 1, right);
}

int main() {
    vector<int> nums = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int index = binarySearch(nums, 0, 0, nums.size());
    cout << "Value found at: " << index << endl;
}