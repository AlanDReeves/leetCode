#include <string>
#include <set>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int maxLength = 0;
        // for each char in string
        for (int i = 0; i < int(s.length()); i++) {
            // start at char and continue until duplicate seen, use set
            std::set<char> seen = {};
            seen.insert(s[i]);
            for (int j = i + 1; j < int(s.length()); j++) {
                if (seen.count(s[j]) == 0) {
                    seen.insert(s[j]);
                } else {
                    break;
                }
            }
            // see if this is the max seen so far and record if so
            int length = seen.size();
            if (length > maxLength) {
                maxLength = length;
            }
        }
        // return max seen
        return maxLength;
    }
};