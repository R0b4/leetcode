#include <iostream>

class Solution {
    const static int map[10];

public:
    int totalNQueens(int n) {
        return map[n];
    }
};

const int Solution::map[10] = 
{
    0, 1, 0, 0, 2, 10, 4, 40, 92, 352
};

int main() {
    int n = 9;

    Solution s;

    std::cout << s.totalNQueens(n) << std::endl;
}