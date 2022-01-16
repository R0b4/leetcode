#include <iostream>

using namespace std;

class Solution {
public:
    const static int n = 35000;
    const static unsigned long mod = 1000000007;

    bool checknum(string num, int k, int i) {
        int num_ib = k - i - i - 1;
        int num_i = k - i;

        if (num_ib < 0) return false;

        for (int j = 0; j <= i; j++) {
            if (num[j + num_ib] > num[j + num_i]) return false;
        }

        return true;
    }

    int numberOfCombinations(string num) {
        long table[2][n];
        for (int i = 0; i < num.size(); i++) table[1][i] = 0;

        long end = 0;

        int i = 0, t = 0;
        for (int j = num.size() - 1; i < j; i++, j--, t ^= 1) {
            for (int k = 0; k < j; k++) {
                long v = table[t ^ 1][k];
                int ib = k - i - 1;
                if (ib == -1) v += 1;
                else if (ib >= 0) {
                    v += table[!checknum(num, k, i) ^ t][ib];
                }

                table[t][k] = v;
            }

            end += table[!checknum(num, num.size() - 1, i) ^ t][num.size() - i - 2];
        }

        t ^= 1;

        for (; i < num.size() - 1; i++) {
            end += table[t][num.size() - i - 2];
        }

        end++;
        return end;
    }
};

int main() {
    std::string num = "4613281";

    Solution s;

    printf("%i\n", s.numberOfCombinations(num));
}