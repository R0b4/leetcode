#include <iostream>

using namespace std;

#define MAX_LEN 50000

class Solution {
public:
    string shortestPalindrome(string s) {
        int p = -1;
        for (int i = s.size() - 1; i >= 0 && p < 0; i--) {
            for (int j = 0, k = i;; j++, k--) {
                printf("%i %i\n");
                if (s[j] != s[k]) break;
                if (k <= j) {
                    p = i + 1;
                    break;
                }
            }
        }

        if (p < 0) return s;

        char out[MAX_LEN];
        int out_i = 0;
        for (int i = s.size() - 1; i >= p; i--) {
            out[out_i++] = s[i];
        }
        for (int i = 0; i < s.size(); i++) {
            out[out_i++] = s[i];
        }

        return string(out, out_i);
    }
};

int main() {
    std::string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

    Solution s;

    printf("%s\n", s.shortestPalindrome(str).c_str());
}