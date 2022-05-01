#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct num_count_pair {
    int n, c;

    inline num_count_pair() = default;
    constexpr num_count_pair(int n, int c)
        : n(n), c(c) {}
    
    constexpr bool operator>(const num_count_pair &other) const { return c > other.c; }
    constexpr bool operator<(const num_count_pair &other) const { return c < other.c; }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> count;

        for (auto n : nums) {
            auto it = count.find(n);
            if (it == count.end()) {
                count.insert(make_pair(n, 1));
            } else {
                it->second++;
            }
        }

        vector<num_count_pair> countv;
        countv.reserve(count.size());
        
        for (const auto &[n, c] : count) {
            countv.emplace_back(n, c);
        }

        sort(countv.begin(), countv.end(), greater<num_count_pair>());

        vector<int> res;
        res.reserve(k);

        for (int i = 0; i < k; i++) {
            res.push_back(countv[i].n);
        }

        return res;
    }
};

int main() {
    vector<int> nums = { 1, 1, 1, 2, 2, 3 };
    int k = 2;

    Solution s;

    auto res = s.topKFrequent(nums, k);
    for (auto n : res) {
        cout << n << ' ';
    }
    cout << endl;
}