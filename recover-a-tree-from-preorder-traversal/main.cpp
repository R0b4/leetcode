#include <iostream>
#include <stack>
#include <ctype.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int get_num(const string &s, int &pos) {
    int n = 0;

    for (int i = pos; i < s.size() && isdigit(s[i]) ; i++) {
        n *= 10;
        n += s[i] - '0';
        pos++;
    }

    return n;
}

int count_dashes(const string &s, int &pos) {
    for (int i = pos, j = 0; i < s.size(); i++, j++) {
        if (s[i] != '-') return j;
        pos++;
    }

    return 0;
}

int usednodes = 0;
TreeNode nodebuffer[1000];

TreeNode *get_new_node() {
    return &nodebuffer[usednodes++];
}

struct SetUsedToZero {
    ~SetUsedToZero() {
        usednodes = 0;
    }
};

template<typename T, size_t S>
struct static_stack {
    T arr[S];
    int pos;

    constexpr static_stack()
        : pos(0) {}

    inline void push(const T &obj) {
        arr[pos++] = obj;
    }

    inline void pop() {
        pos--;
    }

    inline const T &top() {
        return arr[pos - 1];
    }

    inline size_t size() {
        return pos;
    }
};

class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        SetUsedToZero settozeronodes;

        auto *top = get_new_node();
        int str_pos = 0;

        *top = TreeNode(get_num(traversal, str_pos));

        static_stack<TreeNode *, 1000> stk;
        stk.push(top);

        for (;;) {
            int ndepth = count_dashes(traversal, str_pos);
            if (ndepth == 0) {
                return top;
            }

            int num = get_num(traversal, str_pos);

            if (ndepth == stk.size()) {
                auto t = stk.top();
                t->left = get_new_node();
                *t->left = TreeNode(num);
                stk.push(t->left);
            } else if (ndepth < stk.size()) {
                for (; ndepth < stk.size(); ) stk.pop();

                auto t = stk.top();
                t->right = get_new_node();
                *t->right = TreeNode(num);
                stk.push(t->right);
            }
        }
    }
};

int main() {
    string traversel = "1-2--3--4-5--6--7";

    Solution s;

    cout << s.recoverFromPreorder(traversel) << endl;
}