#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long r = 0;
        for (long i = x; i; i /= 10) r = r * 10 + i % 10;

        return r == x;
    }
};

int main() {
    int n = 121;

    Solution s;

    printf("%s\n", s.isPalindrome(n) ? "true" : "false");
}