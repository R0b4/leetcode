#include <map>
#include <vector>
#include <iostream>

using namespace std;

struct t {
    int row;
    int col_a;
    int col_b;

    bool operator<(const t b) const {
        if (row != b.row) return row > b.row;
        if (col_a != b.col_a) return col_a > b.col_a;
        if (col_b != b.col_b) return col_b > b.col_b;
        return true;
    }

    t move(int dcol_a, int dcol_b) {
        t n = *this;
        n.row += 1;
        n.col_a += dcol_a;
        n.col_b += dcol_b;
        return n;
    }
};

struct state {
    int cache[70][70][70];
    vector<vector<int>>& grid;

    state(vector<vector<int>>& grid) : grid(grid) {}
};

bool isvalid(state &s, t tt) {
    if (tt.row >= s.grid.size() || tt.row < 0) return false;
    int colcount = s.grid[0].size();
    if (tt.col_a >= colcount || tt.col_a < 0) return false;
    if (tt.col_b >= colcount || tt.col_b < 0) return false;
    return true;
}

int dp(state &s, t tt) {
    if (!isvalid(s, tt)) return 0;

    int &chache_loc = s.cache[tt.row][tt.col_a][tt.col_b];
    if (chache_loc != -1) {
        return chache_loc;
    }

    auto row = s.grid[tt.row];
    int sum = row[tt.col_a];
    if (tt.col_a != tt.col_b) {
        sum += row[tt.col_b];
    }
    
    int max = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            int d = dp(s, tt.move(i, j));
            if (d > max) max = d;
        }
    }
    sum += max;

    chache_loc = sum;
    return sum;
}

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        state s(grid);
        int colcount = grid[0].size();
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                for (int k = 0; k < grid[0].size(); k++) {
                    s.cache[i][j][k] = -1;  
                } 
            }
        }

        t tt;
        tt.row = 0;
        tt.col_a = 0;
        tt.col_b = grid[0].size() - 1;

        return dp(s, tt);
    }
};

int main() {
    vector<vector<int>> grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    Solution s;
    printf("%i\n", s.cherryPickup(grid));
}