#include <vector>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
        struct ListNode n;
        bool carry = false;
        bool firstit = true;
        for (struct ListNode *c1 = l1, *c2 = l2, *c = &n;; c = c->next, firstit = false) {
            int sum = carry;
            if (c1) {
                sum += c1->val;
                c1 = c1->next;
                carry = true;
            }
            if (c2) {
                sum += c2->val;
                c2 = c2->next;
                carry = true;
            }
            if (!(carry || firstit)) break;

            carry = sum > 9;
            if (carry) sum -= 10;

            c->next = (struct ListNode *)malloc(sizeof(ListNode));
            c->next->next = NULL;
            c->next->val = sum;
        }

        return n.next;
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

void print_list(ListNode *head) {
    for (; head; head = head->next) {
        printf("%i ", head->val);
    }
    printf("\n");
    fflush(stdout);
}

int main() {
    ListNode *l1 = construct_linked_list({2, 4, 3});
    ListNode *l2 = construct_linked_list({5, 6, 4});

    Solution s;
    print_list(s.addTwoNumbers(l1, l2));
}