#include <stdio.h>
#include <algorithm>

class Solution {
public:
    int maximumSwap(int num) {
        int peak = 0;
        int peak_mult = 0;

        int last_digit_smaller = 0;
        int last_digit_smaller_mult = 0;

        int last_digit = 0;
        int last_digit_mult = 0;
        for (int mult = 1, i = num; i; i /= 10, mult *= 10) {
            int digit = i % 10;

            if (digit < last_digit) {
                if (peak < last_digit) {
                    peak = last_digit;
                    peak_mult = last_digit_mult;
                }
            }

            if (digit < peak) {
                last_digit_smaller = digit;
                last_digit_smaller_mult = mult;
            }

            if (digit != last_digit) {
                last_digit = digit;
                last_digit_mult = mult;
            }
        }

        return num + (last_digit_smaller - peak) * peak_mult + (peak - last_digit_smaller) * last_digit_smaller_mult;
    }
};

int main() {
    Solution s;
    int n = 9991;

    printf("%i\n", s.maximumSwap(n));
}