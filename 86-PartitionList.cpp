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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return NULL;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = head;
        ListNode* pre = dummy;
        ListNode* node = new ListNode(0);//此处node不能为空指针 不然就会造成空指针成员访问的错误
        ListNode* rec = node;
        while (cur != NULL) {
            if (cur->val < x) {
                node->next = cur;
                node = node->next;
                pre->next = cur->next;
                cur = cur->next;
            } else {
                pre = pre->next;
                cur = cur->next;
            }
        }
        node->next = dummy->next;
        return rec->next;
    }
};