#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        ListNode* next = head->next;
        bool repeat = false;
        while(next != NULL) {
            if (next->val == cur->val) {
                next = next->next;
                repeat = true;
            } else {
                if (repeat) {
                    pre->next = next;
                    cur = next;
                    next = next->next;
                    repeat = false;
                } else {
                    pre = cur;
                    cur = next;
                    next = next->next;
                }
            }
        }
        if (repeat) pre->next = NULL;
        return dummy->next;
    }
};
class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        while (pre->next) {
            ListNode* cur = pre->next;
            if (cur->next && cur->val == (cur->next)->val) cur = cur->next;
            else {
                if (cur == pre->next) pre = cur;
                else pre->next = cur->next;
            }
        }
        return dummy->next;
    }
};