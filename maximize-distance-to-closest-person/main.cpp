#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int max = 0;
        for (max = 0; !seats[max]; max++);
        for (int i = max, j = max; i < seats.size(); i++) {
            if (seats[i]) {
                int d = (i - j) >> 1;
                if (d > max) max = d;
                j = i;
            }
        }
        for (int i = seats.size() - 1;; i--) {
            if (seats[i]) {
                int d = seats.size() - 1 - i;
                if (d > max) max = d;
                break;
            }
        }

        return max;
    }
};

int main() {
    std::vector<int> seats = {1, 0, 0, 0, 1, 0, 1 };

    Solution s;

    printf("%i\n", s.maxDistToClosest(seats));
}