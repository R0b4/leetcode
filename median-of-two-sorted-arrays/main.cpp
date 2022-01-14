#include <vector>
#include <stdio.h>

using namespace std;

double av(int a, int b) {
    return (double)(a + b) / 2.0;
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    }
};

int main() {
    std::vector<int> a = {1};
    std::vector<int> b;

    Solution s;

    printf("%f\n", s.findMedianSortedArrays(a, b));
}