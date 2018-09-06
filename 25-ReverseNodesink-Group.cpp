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
    bool isMultik(ListNode* head, int k) {
        if (head == NULL) return false;
        while(--k) {
            head = head->next;
            if (head == NULL)
            return false;
        }
        return true;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans = head;
        ListNode* node;
        int k2;
        if(k == 1)
        return head;
        while (isMultik(head, k)) {
            node = head;
            for (int i = 0; i < k - 1; i++) {
            int cnt = k - i;
            head = node;
            while (--cnt) {
                swap(head->val, (head->next)->val);
                head = head->next;
            }
        }
        k2 = k;
        while (--k2) {
            head = head->next;
        }
        } 
        return ans;      
    }
};
class Solution2 {
public:
    ListNode* reverseKGroup(ListNode* head, int k){
        if (head == NULL || k == 1) return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy;
        pre->next = head;
        ListNode* cur = head;
        int i = 0;
        while (cur) {
            i++;
            if (i % k == 0) {
                pre = reverseOneGroup(pre, cur->next);
                cur = pre->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
    ListNode *reverseOneGroup(ListNode *pre, ListNode *next) {
        ListNode* last  = pre->next;
        ListNode* cur = last->next;
        while (cur != next) {
            last->next = cur->next;
            cur->next = pre->next;//不能写成 cur->next = last 
            pre->next = cur;
            cur = last->next;
        }
        return last;
    }
    
};
int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    (head->next)->next = new ListNode(3);
    ((head->next)->next)->next = new ListNode(4);
    (((head->next)->next)->next)->next = new ListNode(5);
    ListNode* node = s.reverseKGroup(head, 2);

    while(node!=NULL) {
        cout << node->val;
        node = node->next;
    }
}