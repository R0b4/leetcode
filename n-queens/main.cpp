#include <iostream>
#include <vector>
#include <utility>
#include <inttypes.h>

using namespace std;

class Board {
private:
    const static std::pair<int, int> dirs[8];
    std::vector<std::vector<std::pair<bool, char>>> board;

public:
    const int n;

    inline Board(int n)
        : n(n), board(n, std::vector<std::pair<bool, char>>(n, std::make_pair(false, 0))) {}

    inline bool is_safe(int x, int y) const {
        return board[x][y].second == 0;
    }

    inline bool is_occupied(int x, int y) const {
        return board[x][y].first;
    }

    inline bool is_on_board(int x, int y) const {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    
    void place_queen(int x, int y) {
        board[x][y].first = true;
        board[x][y].second++;

        for (auto [dx, dy] : dirs){
            for (int xt = x + dx, yt = y + dy; is_on_board(xt, yt); xt += dx, yt += dy) {
                board[xt][yt].second++;
            }
        }
    }

    void remove_queen(int x, int y) {
        board[x][y].first = false;
        board[x][y].second--;

        for (auto [dx, dy] : dirs){
            for (int xt = x + dx, yt = y + dy; is_on_board(xt, yt); xt += dx, yt += dy) {
                board[xt][yt].second--;
            }
        }
    }

    void get_str(std::vector<std::string> &res) const {
        res.reserve(n);
        for (const auto &v : board) {
            res.emplace_back(n, '.');
            auto &str = res.back();

            for (int j = 0; j < n; j++) {
                if (v[j].first) str[j] = 'Q';
            }
        }
    }
};

const std::pair<int, int> Board::dirs[8] = 
{
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1}
};

void nqueen_rec(int c, std::pair<int, int> start, Board &b, std::vector<std::vector<std::string>> &result) {
    if (c == b.n) {
        result.emplace_back();
        auto &v = result.back();
        b.get_str(v);
        return;
    }

    for (int i = start.first; i < b.n; i++) {
        for (int j = (i == start.first ? start.second : 0); j < b.n; j++) {
            if (b.is_safe(i, j)) {
                b.place_queen(i, j);
                nqueen_rec(c + 1, std::make_pair(i, j), b, result);
                b.remove_queen(i, j);
            }
        }
    }
}

std::vector<std::vector<std::string>> nqueen(int n) {
    Board b(n);
    std::vector<std::vector<std::string>> result;

    nqueen_rec(0, std::make_pair(0, 0), b, result);

    return result;
}

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        return nqueen(n);
    }
};

int main() {
    int n = 9;

    Solution s;

    auto res = s.solveNQueens(n);

    for (const auto &v : res) {
        for (const auto &str : v) {
            std::cout << str << std::endl;
        }
        std::cout << std::endl;
    }
}