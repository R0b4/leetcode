#include <iostream>
#include <array>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        array<int, 'z' - 'a' + 1> count;
        count.fill(0);

        for (int i = 0; i < s.size(); i++) count[s[i] - 'a']++;

        for (int i = 0; i < s.size(); i++) {
            if (count[s[i] - 'a'] == 1) return i;
        }

        return -1;
    }
};

int main() {
    string str = "loveleetcode";

    Solution s;

    cout << s.firstUniqChar(str) << endl;
}