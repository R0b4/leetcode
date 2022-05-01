#include <vector>
#include <stdio.h>
#include <stdint.h>

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        std::vector<int> number;

        int p1 = 0, p2 = 0;

        int total_size = nums1.size() + nums2.size();
        int total_used = 0;

        for (int i = k - 1; i >= 0; i--) {
            int total_left = total_size - total_used;

            int p1_max;
            int max_digit1 = INT32_MIN;
            for (int j = p1; j < (p1 + total_left - i) && j < nums1.size(); j++) {
                if (nums1[j] > max_digit1) {
                    max_digit1 = nums1[j];
                    p1_max = j;
                }
            }

            int p2_max;
            int max_digit2 = INT32_MIN;
            for (int j = p2; j < (p2 + total_left - i) && j < nums2.size(); j++) {
                if (nums2[j] > max_digit2) {
                    max_digit2 = nums2[j];
                    p2_max = j;
                }
            }

            if (max_digit1 > max_digit2) {
                p1 = p1_max + 1;
                number.push_back(max_digit1);
            } else {
                p2 = p2_max + 1;
                number.push_back(max_digit2);
            }
        }

        return number;
    }
};

int main() {
    Solution s;

    std::vector<int> nums1 = {6,7};
    std::vector<int> nums2 = {6,0,4};

    int k = 5;

    std::vector<int> res = s.maxNumber(nums1, nums2, k);

    for (int i = 0; i < res.size(); i++) {
        printf("%i ", res[i]);
    }
    printf("\n");
}