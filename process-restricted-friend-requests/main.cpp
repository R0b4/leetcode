#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

template<typename T>
bool sets_overlap(const std::unordered_set<T> &a, const std::unordered_set<T> &b) {
    if (b.size() > a.size()) return sets_overlap(b, a);

    for (const T &p : b) {
        if (a.find(p) != a.end()) return true;
    }

    return false;
}

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<int> itogroup(n);
        vector<unordered_set<int>> groups(n);
        vector<unordered_set<int>> group_restrictions(n);

        for (int i = 0; i < n; i++) {
            itogroup[i] = i;
            groups[i] = {i};
        }

        for (const auto &v : restrictions) {
            group_restrictions[v[0]].insert(v[1]);
            group_restrictions[v[1]].insert(v[0]);
        }

        vector<bool> res(requests.size());
        for (int i = 0; i < requests.size(); i++) {
            const auto &v = requests[i];

            if (itogroup[v[0]] == itogroup[v[1]]) {
                res[i] = true;
                continue;
            }

            auto groupid0 = itogroup[v[0]];
            auto groupid1 = itogroup[v[1]];

            auto &group0 = groups[groupid0];
            auto &group1 = groups[groupid1];

            auto &groupres0 = group_restrictions[groupid0];
            auto &groupres1 = group_restrictions[groupid1];

            if (sets_overlap(group0, groupres1) || sets_overlap(group1, groupres0)) {
                res[i] = false;
                continue;
            } else {
                res[i] = true;
            }

            for (int p : group1) itogroup[p] = groupid0;
            
            group0.insert(group1.begin(), group1.end());
            groupres0.insert(groupres1.begin(), groupres1.end());

            group1.clear();
            groupres1.clear();
        }

        return res;
    }
};

int main() {
    int n = 3;
    vector<vector<int>> restrictions = 
    {
        {0, 1}
    };

    vector<vector<int>> requests = 
    {
        {0, 2},
        {2, 1}
    };

    Solution s;

    auto r = s.friendRequests(n, restrictions, requests);
    for (auto b : r) {
        cout << (b ? 1 : 0) << ' ';
    }
    cout << endl;
}