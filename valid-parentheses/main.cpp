#include <iostream>
#include <string.h>
#include <map>
#include <stack>

using namespace std;

constexpr int bracket_count = 3;
enum bracket_t : int {
    re_b, sq_b, cu_b 
};

struct t {
    t() = default;
    constexpr t(bracket_t type, bool incr) : type(type), incr(incr) {}

    bracket_t type;
    bool incr;
};

std::map<char, t> br_map = {
    {'(', t(re_b, true)}, {')', t(re_b, false)},
    {'[', t(sq_b, true)}, {']', t(sq_b, false)},
    {'{', t(cu_b, true)}, {'}', t(cu_b, false)}
};

class Solution {
public:
    bool isValid(string s) {
        int depth[bracket_count];
        for (int i = 0; i < bracket_count; i++) depth[i] = 0;

        std::stack<bracket_t> openhist;

        for (int i = 0; i < s.size(); i++) {
            t br = br_map[s[i]];
            if (br.incr) {
                depth[br.type]++;
                openhist.push(br.type);
            }
            else {
                depth[br.type]--;
                if (depth[br.type] < 0) return false;

                if (openhist.top() != br.type) return false;
                openhist.pop();
            }
        }

        for (int i = 0; i < bracket_count; i++) if (depth[i]) return false;

        return true;
    }
};

int main() {
    string a = "()()";
    Solution s;
    
    printf("%s\n", s.isValid(a) ? "true" : "false");
}