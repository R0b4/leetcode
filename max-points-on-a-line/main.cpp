#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int getpointsonline(vector<vector<int>>& points, int a, int b) {
        int dx = points[a][0] - points[b][0];
        int dy = points[a][1] - points[b][1];

        int count = 2;
        for (int i = b + 1; i < points.size(); i++) {
            int dxi = (points[a][0] - points[i][0]);
            int dyi = (points[a][1] - points[i][1]);

            if (dxi * dy == dyi * dx) count++;
        }

        return count;
    }

    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 2) return points.size();

        int max = 2;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int n = getpointsonline(points, i, j);

                if (n > max) max = n;
            }
        }

        return max;
    }
};

int main() {
    std::vector<std::vector<int>> points = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};

    Solution s;

    printf("%i\n", s.maxPoints(points));
}