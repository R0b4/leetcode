#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned int udi = dividend < 0 ? ~(unsigned)dividend + 1U : dividend;
        unsigned int ude = divisor < 0 ? ~(unsigned)divisor + 1U : divisor;

        int maxsh = (sizeof(int) << 3);
        for (unsigned int i = ude; i; i >>= 1, maxsh -= 1);

        unsigned int res = 0;
        for (int i = maxsh; i >= 0; i--) {
            unsigned int min = ude << i;
            if (min > udi) continue;

            udi -= min;
            res |= 1 << i;
        }

        if (dividend < 0 ^ divisor < 0) res = ~res + 1;
        return res;
    }
};

int main() {
    int divident = -2147483648;
    int divisor = -1;

    Solution s;

    printf("%i\n", s.divide(divident, divisor));
}