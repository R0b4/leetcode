#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        constexpr int maxbitsize = 10000;
        char outbits[maxbitsize + 1];
        outbits[maxbitsize] = '\0';

        bool carry = false;

        const char *as = &a[a.size() - 1];
        const char *bs = &b[b.size() - 1];
        char *os = outbits + maxbitsize;

        for (int i = 0;; i++) {
            int ab = i < a.size() ? *(as--) - '0' : 0;
            int bb = i < b.size() ? *(bs--) - '0' : 0;

            int psum = ab ^ bb;
            int sum = psum ^ carry;
            if (!psum) carry = false;
            if (ab & bb) carry = true;

            os--;
            *os = sum + '0';

            int ip1 = i + 1;
            if (ip1 >= a.size() && ip1 >= b.size() && !carry) return string(os);
        }
    }
};

int main() {
    string a = "1010";
    string b = "1011";

    Solution s;

    printf("%s\n", s.addBinary(a, b).c_str());
}