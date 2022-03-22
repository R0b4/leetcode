#include <iostream>

using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        std::string str(n, 'a');

        int missing = k - n;
        for (int i = n - 1; i >= 0; i--) {
            int added = std::min(missing, 'z' - 'a');
            
            missing -= added;
            str[i] = 'a' + added;
        }

        return str;
    }
};

int main() {
    int n, k;

    scanf("%i", &n);
    scanf("%i", &k);

    Solution s;

    std::cout << s.getSmallestString(n, k) << std::endl;
}