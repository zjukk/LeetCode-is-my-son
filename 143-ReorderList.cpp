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
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        ListNode* h = head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        ListNode* next = head->next;
        while (1) {
            while (cur->next && cur->next->next != h) {
                pre = cur;
                cur = cur->next;
            }
            h->next = cur;
            cur->next = next;
            //update
            pre = h;
            cur = pre->next;
            h = next;
            next = next->next;
            if (next && next->next == h) {
                h->next = NULL;
                return;
            }
            if (next->next && next->next->next == h) {
                h->next->next = NULL;
                return;
            }
        } 
    }
};

// 这道链表重排序问题可以拆分为以下三个小问题：

// 1. 使用快慢指针来找到链表的中点，并将链表从中点处断开，形成两个独立的链表。

// 2. 将第二个链翻转。

// 3. 将第二个链表的元素间隔地插入第一个链表中。
class Solution2 {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        ListNode* slow = head->next;
        ListNode* fast = slow->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* rhead = reverse(slow);
        while (head != rhead && head->next != rhead) {
            ListNode* next = head->next;
            head->next = rhead;
            rhead = rhead->next;
            head->next->next = next;//rhead的值已经发生变化，而head->next保存了rhead原来的值
            head = next;
        }
    }
    ListNode* reverse(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};