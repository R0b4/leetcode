#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string res;
        res.reserve(s.size());
        int period = (numRows - 1) << 1;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < s.size(); j += period) {
                int i1 = j + i;
                int i2 = j + period - i;

                if (i1 < s.size()) {
                    res += s[i1];
                }

                if (i1 != i2 && i && i2 < s.size()) {
                    res += s[i2];
                }
            }
        }

        return res;
    }
};

int main() {
    string in = "paypalishiring";
    int rows = 5;

    Solution s;

    std::cout << s.convert(in, rows) << std::endl;
}