#include <iostream>
#include <algorithm>
#include <ctype.h>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        const size_t reserved = s.size() * (k + 1) / k;
        
        string res;
        res.reserve(s.size() * (k + 1) / k);

        for (int i = s.size() - 1, j = 0; i >= 0; i--) {
            if (s[i] == '-') continue;

            if (j == k) {
                j = 0;
                res += '-';
            }

            res += toupper(s[i]);
            j++;
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    string in = "5F3Z2e9waaaa";
    int k = 4;

    Solution s;

    cout << s.licenseKeyFormatting(in, k) << endl;
}