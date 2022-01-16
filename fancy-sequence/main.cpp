#include <iostream>
#include <vector>

#define MOD 1000000007

void mod_sq(unsigned long &n, unsigned long mod) {
    n = (n * n) % mod;
}

void mod_mult(unsigned long &n, unsigned long b, unsigned long mod) {
    n = (n * b) % mod;
}

void mod_add(unsigned long &n, unsigned long b, unsigned long mod) {
    n = (n + b) % mod;
}

unsigned long mod_pow(unsigned long base, unsigned long exp, unsigned long mod) {
    unsigned long res = 1;
    for (; exp; exp >>= 1, mod_sq(base, mod)) {
        if (exp & 1) mod_mult(res, base, mod);
    }

    return res;
}

class Fancy {
public:
    std::vector<unsigned long> nums;
    
    unsigned long add;
    unsigned long mult;

    Fancy() {
        add = 0;
        mult = 1;
    }
    
    void append(int val) {
        val = (MOD + val) - add;
        val = (val * mod_pow(mult, MOD - 2, MOD)) % MOD;
        nums.push_back(val);
    }
    
    void addAll(int inc) {
        mod_add(add, inc, MOD);
    }
    
    void multAll(int m) {
        mod_mult(mult, m, MOD);
        mod_mult(add, m, MOD);
    }
    
    int getIndex(int idx) {
        if (idx >= nums.size()) return -1;

        unsigned long n = nums[idx];
        mod_mult(n, mult, MOD);
        mod_add(n, add, MOD);

        return (int)n;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */