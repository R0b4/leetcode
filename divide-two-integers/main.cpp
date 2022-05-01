#include <iostream>

class Solution {
public:
    inline int flipsign(int n) {
        return (signed)(~((unsigned)n) + 1); 
    }

    unsigned int abs(int n) {
        if (n < 0) return flipsign(n);
        else return n;
    }

    unsigned int posdivide(unsigned int a, unsigned int b) {
        unsigned int maxsh = (sizeof(int) << 3);
        for (unsigned int i = b; i; i >>= 1, maxsh -= 1);

        unsigned int res = 0;
        for (int i = maxsh; i >= 0; i--) {
            unsigned int min = b << i;
            if (min > a) continue;

            a -= min;
            res |= 1 << i;
        }

        return res;
    }

    int divide(int dividend, int divisor) {
        bool negative = (dividend < 0) ^ (divisor < 0);

        unsigned int res = posdivide(abs(dividend), abs(divisor));

        if (!negative && res > INT32_MAX) return INT32_MAX;

        if (negative) return flipsign(res);
        else return res;
    }
};

int main() {
    int divident = 7;
    int divisor = -3;

    Solution s;

    printf("%i\n", s.divide(divident, divisor));
}