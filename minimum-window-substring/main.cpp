#include <iostream>
#include <array>
#include <unordered_map>

using namespace std;

class Solution {
public:
    template<typename A, typename M>
    bool arr_contains(const A &arr, const M &map) {
        for (const auto &[ch, count] : map) {
            if (arr[ch] < count) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        const static int char_offset = 'A';
        const static int char_count = 'z' - 'A' + 1;

        unordered_map<char, int> target;
        for (char c : t) {
            c -= char_offset;
            auto it = target.find(c);
            if (it == target.end()) {
                target.insert(make_pair(c, 1));
            } else {
                it->second++;
            }
        }

        int size = INT32_MAX;
        pair<int, int> maxsub;

        array<int, char_count> str_count;
        fill(str_count.begin(), str_count.end(), 0);

        int last = 0;
        int begin = 0;
        for (;;) {
            for (; last < s.size(); last++) {
                str_count[s[last] - char_offset]++;
                if (arr_contains(str_count, target)) break;
            }

            if (!arr_contains(str_count, target)) break;

            for (; begin <= last; begin++) {
                str_count[s[begin] - char_offset]--;
                if (!arr_contains(str_count, target)) break;
            }


            int nsize = last - begin + 1;
            if (nsize < size) {
                size = nsize;
                maxsub = make_pair(begin, nsize);
            }

            last = last + 1;
            begin = begin + 1;
        }

        if (size == INT32_MAX) return "";
        else return s.substr(maxsub.first, maxsub.second);
    }
};

int main() {
    string str = "cabwefgewcwaefgcf";
    string t = "cae";

    Solution s;

    cout << s.minWindow(str, t) << endl;
}