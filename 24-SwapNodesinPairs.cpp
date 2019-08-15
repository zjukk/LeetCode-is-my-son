#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* ans = head;
        while (head != NULL && head->next != NULL) {
            swap(head->val, (head->next)->val);
            head = (head->next)->next;
        }
        return ans;
    }
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* t = head->next;
        head->next = swapPairs(head->next->next);
        t->next = head;
        return t;
    }
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* res = cur;
        while (cur && pre) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre->next = (next && next->next) ? next->next : next;
            pre = next;
            if (pre) cur = pre->next;
        }
        return res;
    }
};