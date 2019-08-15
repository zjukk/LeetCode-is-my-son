#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//要求O(n) = nlog(n)
//merge sort
//链表的归并排序空间复杂度为O(1)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* slow = head, *fast = head, *pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //退出循环时slow保存的是中间结点，pre保存的是slow的前一个结点，将其指向空节点
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        // while (l1) {
        //     cur->next = l1;
        //     l1 = l1->next;
        //     cur = cur->next;
        // }
        // while (l2) {
        //     cur->next = l2;
        //     l2 = l2->next;
        //     cur = cur->next;
        // }
        //more simple
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return dummy->next;
    }
};