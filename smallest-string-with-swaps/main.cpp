#include <iostream>

#include <vector>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<vector<int>> groups;

        {
            vector<vector<int>> graph(s.size());
            vector<bool> visited(s.size(), false); 

            for (const auto &v : pairs) {
                graph[v[0]].push_back(v[1]);
                graph[v[1]].push_back(v[0]);
            }

            for (int i = 0; i < s.size(); i++) {
                if (visited[i]) continue;

                groups.emplace_back();
                auto &current_group = groups[groups.size() - 1];

                std::stack<int> search;
                search.push(i);

                for (; !search.empty();) {
                    int n = search.top();
                    search.pop();

                    if (visited[n]) continue;
                    visited[n] = true;
                    current_group.push_back(n);

                    for (auto c : graph[n]) {
                        search.push(c);
                    }
                }

                std::sort(current_group.begin(), current_group.end());
            }
        }

        vector<vector<char>> groupsstr;
        for (const auto &g : groups) {
            groupsstr.emplace_back(g.size());
            auto &v = groupsstr[groupsstr.size() - 1];

            for (int i = 0; i < g.size(); i++) {
                v[i] = s[g[i]];
            }

            std::sort(v.begin(), v.end());
        }

        string res(s.size(), ' ');
        for (int i = 0; i < groups.size(); i++) {
            for (int j = 0; j < groups[i].size(); j++) {
                res[groups[i][j]] = groupsstr[i][j];
            }
        }

        return res;
    }
};

int main() {
    string in = "dcab";
    vector<vector<int>> pairs = 
    {
        {0, 3},
        {1, 2},
        {0, 2}
    };

    Solution s;

    std::cout << s.smallestStringWithSwaps(in, pairs) << std::endl;
}