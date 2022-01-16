#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    const static int cc = 3;

    void sortColors(vector<int>& nums) {
        int c[cc];
        for (int i = 0; i < cc; i++) c[i] = 0;
        for (int i = 0; i < nums.size(); i++) c[nums[i]]++;
        
        
        for (int i = 0, j = 0; i < cc; i++) {
            for (; c[i]--; j++) {
                nums[j] = i;
            }
        }
    }
};

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    Solution s;

    s.sortColors(nums);

    for (int i = 0; i < nums.size(); i++) {
        printf("%i\n", nums[i]);
    }
}