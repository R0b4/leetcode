#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        std::sort(satisfaction.begin(), satisfaction.end(), std::greater<int>());

        int insum = 0;
        int total = 0;
        for (int i = 0; i < satisfaction.size(); i++) {
            if (insum < -satisfaction[i]) break;

            insum += satisfaction[i];
            total += insum;
        }

        return total;
    }
};

int main() {
    std::vector<int> satisfaction = {-1,-8,0,5,-9};

    Solution s;

    printf("%i\n", s.maxSatisfaction(satisfaction));
}