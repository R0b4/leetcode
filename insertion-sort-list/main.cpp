#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode s(INT32_MIN, head);
        ListNode smin(0, &s);
        
        ListNode *last = &s;
        int i = 0;
        for (ListNode *c = head; c; c = c->next, i++) {
            if (c->val >= last->val) {
                last = c;
            } else {
                ListNode *p = &s;
                for (;; p = p->next) {
                    if (p->next->val > c->val) break;
                }

                last->next = c->next;
                c->next = p->next;
                p->next = c;
                c = last;
            }
        }

        return s.next;
    }
};

ListNode *construct_linked_list(std::vector<int> list) {
    ListNode n;
    ListNode *c = &n;
    for (int i = 0; i < list.size(); i++, c = c->next) {
        c->next = new ListNode(list[i]);
    }

    return n.next;
}

int main() {
    ListNode *l = construct_linked_list({-1,5,3,4,0});

    Solution s;

    for (ListNode *c = s.insertionSortList(l); l; l = l->next) {
        printf("%i\n", l->val);
    }
}
