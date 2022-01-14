#include <vector>
#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dkth = head;
        for (int i = 1; dkth->next && i < k; i++, dkth = dkth->next);

        ListNode *start = dkth;
        ListNode *c = head;

        bool stop = false;
        do {
            {
                ListNode *t = dkth->next;
                for (int i = 0; dkth && i < k; i++, dkth = dkth->next);
                if (!dkth) {
                    dkth = t;
                    stop = true;
                }
            }

            ListNode *last = dkth;
            for (int i = 0; i < k && c; i++) {
                ListNode *t = c->next;
                c->next = last;
                last = c;
                c = t;
            }
        } while (!stop);

        return start;
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
    int k = 8;
    ListNode *list = construct_linked_list({1, 2, 3, 4, 5});

    Solution s;
    ListNode *start = s.reverseKGroup(list, k);

    for (ListNode *c = start; c; c = c->next) {
        printf("%i ", c->val);
    }
    printf("\n");
    fflush(stdout);
}