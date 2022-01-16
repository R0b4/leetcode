#include <vector>
#include <iostream>

class Solution {
public:
    const static int max = 1690;

    int nthUglyNumber(int n) {
        n--;
        int nums[max];
        nums[0] = 1;

        constexpr int pcount = 3;
        constexpr int primes[pcount] = {2, 3, 5};
        int p[pcount];
        for (int i = 0; i < pcount; i++) p[i] = 0;

        for (int i = 1; i <= n; i++) {
            int minn = INT32_MAX;
            for (int j = 0; j < pcount; j++) {
                int num = primes[j] * nums[p[j]];
                if (num < minn) minn = num;
            }

            nums[i] = minn;
            
            for (int j = 0; j < pcount; j++) {
                int num = primes[j] * nums[p[j]];
                if (nums[i] == num) p[j]++;
            }
        }

        return nums[n];
    }
};

int main() {
    int n = 100;

    Solution s;

    printf("%i\n", s.nthUglyNumber(n));
}