class Solution {
public:
    bool isUgly(int n) {
        if (n == 0) return true;

        constexpr int pc = 3;
        constexpr int primes[pc] = {2, 3, 5};

        for (int i = 0; i < pc; i++) {
            for (;;) {
                if (n % primes[i]) break;

                n /= primes[i]; 
            }
        }

        return n == 1;
    }
};

