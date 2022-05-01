#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int wildcards = 0;
        int balance = 0;

        std::stack<int> opens;
        std::stack<int> wilds;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                balance++;
                opens.push(i);
            } else if (s[i] == ')') {
                if (balance == 0) {
                    if (wildcards > 0) {
                        wildcards--;
                    } else {
                        return false;
                    }
                } else {
                    opens.pop();
                    balance--;
                }
            } else {
                wildcards++;
                wilds.push(i);
            }
        }

        for (;;) {
            if (opens.empty()) return true;
            if (wilds.empty()) return false;
            if (opens.top() > wilds.top()) return false;
            opens.pop();
            wilds.pop();
        }

        return true;
    }
};

int main() {
    string in = "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())";

    Solution s;

    const char *res = s.checkValidString(in) ? "true" : "false";
    std::cout << res << std::endl;
}