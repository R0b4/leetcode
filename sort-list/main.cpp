#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeSort(ListNode *l, int n) {
        if (n == 1) {
            l->next = nullptr;
            return l;
        }

        ListNode *l1 = l;
        ListNode *l2 = l;
        for (int i = 0; i < (n >> 1); i++, l2 = l2->next);

        l1 = mergeSort(l1, n >> 1);
        l2 = mergeSort(l2, n - (n >> 1));

        ListNode out;
        for (ListNode *c = &out;; c = c->next) {
            ListNode **max = nullptr;
            if (l1 && l2) {
                if (l1->val < l2->val) {
                    max = &l1;
                } else max = &l2;
            } 
            else if (l1) max = &l1;
            else if (l2) max = &l2;
            else {
                c->next = nullptr;
                break;
            }

            c->next = *max;
            *max = (*max)->next;
        }

        return out.next;
    }

    ListNode *sortList(ListNode *head) {
        int n = 0;
        for (ListNode *c = head; c; c = c->next, n++);

        if (n < 2) return head;

        return mergeSort(head, n);
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
    ListNode *l = construct_linked_list({});

    Solution s;

    for (ListNode *c = s.sortList(l); l; l = l->next) {
        printf("%i\n", l->val);
    }
}
