#include <stdio.h>

void printb(int n) {
    for (unsigned int i = (~0U) ^ (~0U >> 1); i; i >>= 1) {
        printf("%c", n & i ? '1' : '0');
    }
    printf("\n");
}

class Solution {
public:
    int getSum(int a, int b) {
        unsigned int carry = a & b;
        unsigned int abor = a | b;
        
        for (unsigned int i = 1; i; i <<= 1) {
            carry |= (carry << 1) & abor & i;
        }

        return a ^ b ^ (carry << 1);
    }
};

int main() {
    int a = 10, b = -5;

    Solution s;

    printf("%i\n", s.getSum(a, b));
}