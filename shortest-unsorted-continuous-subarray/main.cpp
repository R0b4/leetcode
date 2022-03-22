#include <vector>
#include <stdio.h>
#include <stdint.h>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int p1 = -1;
        for (int i = 0; (i + 1) < nums.size(); i++) {
            if (nums[i] > nums[i + 1]) {
                p1 = i;
                break;
            }
        }

        if (p1 == -1) return 0;

        int p2;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < nums[i - 1]) {
                p2 = i;
                break;
            }
        }

        int ma = INT32_MIN, mi = INT32_MAX;

        for (int i = p1; i <= p2; i++) {
            ma = std::max(ma, nums[i]);
            mi = std::min(mi, nums[i]);
        }

        for (int i = p2; i < nums.size(); i++) {
            if (nums[i] >= ma) break;

            p2 = i;
        }

        for (int i = p1; i >= 0; i--) {
            if (nums[i] <= mi) break;

            p1 = i;
        }

        return 1 + p2 - p1;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {2, 6, 4, 8, 10, 9, 15};

    printf("%i\n", s.findUnsortedSubarray(nums));
}