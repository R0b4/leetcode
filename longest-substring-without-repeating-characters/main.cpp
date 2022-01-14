#include <iostream>
#include <map>

using namespace std;

#define CHAR_AMOUNT (1 << (sizeof(char) << 3) >> 1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[CHAR_AMOUNT];
        for (int i = 0; i < CHAR_AMOUNT; i++) pos[i] = -1;

        int maxcount = 0;
        int imax;

        for (int i = 0, count = 0; i < s.size(); i++) {
            count++;
            if (pos[s[i]] + count <= i) {
                if (count > maxcount) maxcount = count;
            } else {
                i = pos[s[i]];
                count = 0;
            }
            pos[s[i]] = i;
        }

        return maxcount;
    }
};

int main() {
    string str = "dvdf";

    Solution s;

    printf("%i\n", s.lengthOfLongestSubstring(str));
}