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

// 可以用环的思想来做，我们让两条链表分别从各自的开头开始往后遍历，当其中一条遍历到末尾时，
// 我们跳到另一个条链表的开头继续遍历。两个指针最终会相等，而且只有两种情况，一种情况是在交点处相遇，
// 另一种情况是在各自的末尾的空节点处相等。为什么一定会相等呢，因为两个指针走过的路程相同，
// 是两个链表的长度之和，所以一定会相等。
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode* a = headA, *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        int len1 = getLen(headA), len2 = getLen(headB);
        ListNode *a = headA, *b = headB;
        if (len2 > len1) {
            for (int i = 0; i < len2 - len1; ++i) {
                b = b->next;
            }
        } else {
            for (int i = 0; i < len1 - len2; ++i) {
                a = a->next;
            }
        }
        while (a != b) {
            a = a->next;
            b = b->next;
        }
        return a; 
    }
    int getLen(ListNode* head) {
        int cnt = 0;
        while (head) {
            head = head->next;
            ++cnt;
        }
        return cnt;
    }
};