#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

struct char_count_pair {
    char c;
    int f;

    inline char_count_pair() = default;
    constexpr char_count_pair(char c, int f)
        : c(c), f(f) {}

    inline bool operator>(const char_count_pair &other) const { return f > other.f; }
    inline bool operator<(const char_count_pair &other) const { return f < other.f; }
};

class Solution {
public:
    string frequencySort(string s) {
        array<char_count_pair, 'z' - '0' + 1> chars;
        for (int i = 0; i < chars.size(); i++) {
            chars[i] = char_count_pair('0' + i, 0);
        }

        for (char c : s) chars[c - '0'].f++;

        std::sort(chars.begin(), chars.end(), std::greater<char_count_pair>());

        string res(s.size(), '#');
        for (int i = 0, j = 0; i < res.size(); i++) {
            res[i] = chars[j].c;
            if (!--chars[j].f) j++;
        }

        return res;
    }
};

int main() {
    string str = "tree";

    Solution s;

    cout << s.frequencySort(str) << endl;
}