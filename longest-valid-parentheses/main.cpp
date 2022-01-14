#include <iostream>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int depth = 0;
        int counter = 0;
        int max = 0;

        int lastzero;

        for (int i = 0; i < s.size(); i++) {
            counter++;

            if (s[i] == '(') depth++;
            else { depth--;
                if (depth == 0) {
                    if (counter > max) max = counter;
                    lastzero = i;
                } else if (depth < 0) {
                    counter = 0;
                    depth = 0;
                    lastzero = i;
                }
            }
        }

        int lastdepth = depth;

        depth = 0;
        counter = 0;
        if (lastdepth != 0) for (int i = s.size() - 1; i > -1; i--) {
            counter++;

            if (s[i] == ')') depth++;
            else { depth--;
                if (depth == 0) {
                    if (counter > max) max = counter;
                    lastzero = i;
                } else if (depth < 0) {
                    counter = 0;
                    depth = 0;
                    lastzero = i;
                }
            }
        }

        return max;
    }
};

int main() {
    string a = ")(((((()())()()))()(()))(";
    Solution s;
    printf("%i\n", s.longestValidParentheses(a));
}