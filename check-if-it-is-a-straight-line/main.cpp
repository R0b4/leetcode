#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dx = coordinates[0][0] - coordinates[1][0];
        int dy = coordinates[0][1] - coordinates[1][1];

        for (int i = 2; i < coordinates.size(); i++) {
            int dxi = (coordinates[0][0] - coordinates[i][0]);
            int dyi = (coordinates[0][1] - coordinates[i][1]);

            if (dxi * dy != dyi * dx) return false;
        }

        return true;
    }
};

int main() {

}