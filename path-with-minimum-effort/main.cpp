#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct value_pos {
    int value;
    int x, y;

    inline value_pos() = default;
    constexpr value_pos(int val, int x, int y)
        : value(val), x(x), y(y) {}

    static constexpr value_pos create_max() { return value_pos(INT32_MAX, 0, 0); }

    inline bool operator>(const value_pos &other) const {
        return value > other.value;
    }

    inline bool operator<(const value_pos &other) const {
        return value < other.value;
    }
};

value_pos construct_pos(const vector<vector<bool>>& explored, const vector<vector<int>>& heights, const value_pos &t, int dx, int dy) {
    value_pos a;
    
    a.x = t.x + dx;
    a.y = t.y + dy;
    
    if (a.x >= heights.size() || a.x < 0) return value_pos::create_max();
    if (a.y >= heights[0].size() || a.y < 0) return value_pos::create_max();
    if (explored[a.x][a.y]) return value_pos::create_max();

    a.value = std::max(t.value, std::abs(heights[t.x][t.y] - heights[a.x][a.y]));

    return a;
}

inline void constructpush(priority_queue<value_pos, vector<value_pos>, greater<value_pos>> &q, const vector<vector<bool>>& explored, const vector<vector<int>>& heights, const value_pos &t, int dx, int dy) {
    auto p = construct_pos(explored, heights, t, dx, dy);
    if (p.value == INT32_MAX) return;

    q.push(p);
}

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<value_pos, vector<value_pos>, greater<value_pos>> q;
        vector<vector<bool>> explored(heights.size(), vector<bool>(heights[0].size(), false));

        q.push(value_pos(0, 0, 0));

        for (;;) {
            value_pos t = q.top();
            q.pop();

            if (t.x == heights.size() - 1 && t.y == heights[0].size() - 1) return t.value;

            explored[t.x][t.y] = true;

            constructpush(q, explored, heights, t, 1, 0);
            constructpush(q, explored, heights, t, 0, 1);
            constructpush(q, explored, heights, t, -1, 0);
            constructpush(q, explored, heights, t, 0, -1);
        }
    }
};

int main() {
    vector<vector<int>> heights = 
    {
        {1, 2, 2},
        {3, 8, 3},
        {5, 3, 5}
    };

    Solution s;

    cout << s.minimumEffortPath(heights) << endl;
}