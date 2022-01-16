#include <iostream>

class Solution {
public:
    bool check(int n, int *digits) {
        int cdigits[10];
        for (int i = 0; i < 10; i++) cdigits[i] = digits[i];
        for (; n; n /= 10) {
            if (!cdigits[n % 10]--) return false;
        }

        return true;
    }

    bool reorderedPowerOf2(int n) {
        int digits[10];
        int min = 1;
        for (int i = 0; i < 10; i++) digits[i] = 0;

        for (; n; n /= 10, min *= 10) {
            digits[n % 10]++;
        }

        min /= 10;

        int max = min * 10 - 1;

        for (unsigned int i = 1; i; i <<= 1) {
            if (i < min || i > max) continue;

            if (check(i, digits)) return true;
        }

        return false;
    }
};

int main() {
    int n = 265;

    Solution s;

    printf("%s\n", s.reorderedPowerOf2(n) ? "true" : "false");
}