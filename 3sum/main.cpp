#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        int last = INT32_MIN;
        for (auto it = nums.begin(); it != nums.end(); it++) {
            if (*it == last) continue;
            last = *it;

            int lastj = INT32_MIN;
            for (auto jt = it + 1; jt != nums.end(); jt++) {
                if (*jt == lastj) continue;
                lastj = *jt;

                int missing = -(*it + *jt);
                if (!binary_search(jt + 1, nums.end(), missing)) continue;

                res.emplace_back();
                auto &v = res.back();
                v.reserve(3);
                v.push_back(*it);
                v.push_back(*jt);
                v.push_back(missing);
            }
        }
        
        return res;
    }
};

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};

    Solution s;

    auto res = s.threeSum(nums);

    for (const auto &v : res) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << endl;
    }
}