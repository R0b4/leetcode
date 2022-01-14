#include <stdio.h>
#include <iostream>

class Solution {
public:
    int reverse(int x) {
        bool neg = x < 0;
        unsigned int xu = x;

        if (neg) xu = (unsigned int)~x + 1U;
        unsigned int r = 0;

        for (; xu; xu /= 10) {
            int temp = r;
            r *= 10;
            if (temp != r / 10) return 0;

            temp = r;
            int m = xu % 10;
            r += m;
            if (temp != r - m) return 0;
        }

        if (r > INT32_MAX) return 0;

        if (neg) r = ~r + 1;
        return r;
    }
};

int main() {
    int n = -1000000002;

    Solution s;

    printf("%i\n", s.reverse(n));
}