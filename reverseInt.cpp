#include<limits.h>

class Solution {
public:
    int reverse(int x) {
        int y = 0;

        while (x != 0) {
            int carry = x % 10;

            // overflow check
            if (y > INT_MAX / 10 || y < INT_MIN / 10) return 0;
            y *= 10;
            if ((carry > 0 && y > INT_MAX - carry) || ( carry < 0 && y < INT_MIN - carry)) return 0;
            y += carry;

            x /= 10;
        }
        return y;
    }
};

// i.e. if given 123, return 321