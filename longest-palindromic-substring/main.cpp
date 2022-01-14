#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        const char *cs = s.c_str();
        const int len = s.size();

        int max = 0;
        int bestmin, bestmax;
        
        for (int i = 0; i < len; i++) {
            for (int j = 0;; j++) {
                int imin = i - j;
                int imax = i + j;

                if (imin < 0) break;
                if (imax >= len) break;
                if (cs[imin] != cs[imax]) break;

                int jlen = 1 | j << 1;
                
                if (jlen <= max) continue; 

                max = jlen;
                bestmin = imin;
                bestmax = imax;
            }
        }

        for (int i = 1; i < len; i++) {
            for (int j = 0;; j++) {
                int imin = i - j - 1;
                int imax = i + j;

                if (imin < 0) break;
                if (imax >= len) break;
                if (cs[imin] != cs[imax]) break;

                int jlen = (j + 1) << 1;
                if (jlen <= max) continue; 

                max = jlen;
                bestmin = imin;
                bestmax = imax;
            }
        }

        return string(cs + bestmin, bestmax - bestmin + 1);
    }
};


int main() {
    std::string str = "cbbd";

    Solution s;

    printf("%s\n", s.longestPalindrome(str).c_str());
}