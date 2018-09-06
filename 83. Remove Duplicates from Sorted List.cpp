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
        ListNode* cur = head;
        ListNode* next = head->next;
        while (next != NULL) {
            if (cur->val == next->val) {
                next = next->next;
                cur->next = next;
            } else {
                cur = next;
                next = next->next;
            }
        }
        return dummy->next;
    }
};