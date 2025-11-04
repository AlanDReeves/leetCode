#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // using a bit map here is strictly not needed because the problem specifies that the array is sorted.
        // I just wanted to do this for fun/learning
        unsigned char bits[26] = { 0 }; // make 208 bit array, 7 bits larger than needed
        size_t fast = 0, slow = 0;
        for (fast; fast < nums.size(); fast++) {
            // create bitmask to check bit map
            int offset = nums[fast] + 100; // so that -100 becomes 0
            int charSelect = offset / 8; // selects which char in bits contains the correct bit
            int exactBit = offset % 8;
            unsigned char bitMask = 0b1 << exactBit;

            if (!(bits[charSelect] & bitMask)) { // number NOT seen before
                bits[charSelect] = bits[charSelect] | bitMask; // mark as seen without flipping other bits
                nums[slow] = nums[fast];
                slow++;
            } 
        }
        return slow;
    }
};