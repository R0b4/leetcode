#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *merge(vector<ListNode*>& ll, int is, int n) {
        if (n == 1) return ll[is];

        int ndiv2 = n >> 1;
        ListNode *a = merge(ll, is, ndiv2);
        ListNode *b = merge(ll, is + ndiv2, n - ndiv2);

        ListNode res;

        for (ListNode *c = &res; c; c = c->next) {
            ListNode **min = nullptr;
            if (a && b) {
                if (a->val < b->val) {
                    min = &a;
                } else min = &b;
            } else if (a) min = &a;
            else if (b) min = &b;
            else {
                c->next = nullptr;
                break;
            }

            c->next = *min;
            *min = (*min)->next;
        }

        return res.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;

        return merge(lists, 0, lists.size());
    }
};

ListNode *mklist(std::vector<int> list) {
    ListNode n;
    ListNode *c = &n;
    for (int i = 0; i < list.size(); i++, c = c->next) {
        c->next = new ListNode(list[i]);
    }

    return n.next;
}

std::vector<ListNode *> mk2list(std::vector<std::vector<int>> list) {
    std::vector<ListNode *> res;

    for (int i = 0; i < list.size(); i++) {
        res.push_back(mklist(list[i]));
    }

    return res;
}

int main() {
    std::vector<ListNode *> l = mk2list({{1,4,5}, {1,3,4}, {2,6}});

    Solution s;

    for (ListNode *c = s.mergeKLists(l); c; c = c->next) {
        printf("%i\n", c->val);
    }
}
