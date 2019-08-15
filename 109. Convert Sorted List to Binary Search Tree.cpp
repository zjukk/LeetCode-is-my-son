#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
//链表的查找中间点可以通过快慢指针来操作
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return new TreeNode(head->val);
        ListNode* slow = head;//根节点位置
        ListNode* last = slow;
        ListNode* fast = slow;
        while (fast->next && fast->next->next) {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;//根节点的下一个节点
        last->next = NULL;//将链表从中间断开 上一个结点指向空 而非slow->next = NULL;
        TreeNode* cur = new TreeNode(slow->val);
        if (head != slow) cur->left = sortedListToBST(head); //if (head != slow)很重要！！默认当只有2个节点时必为根结点和右结点
        cur->right = sortedListToBST(fast);
        return cur;
    }
};