#include <iostream>
#include <algorithm>
using namespace std;
  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* start = dummy;
        for(int i = 1; i < m; ++i) start = start->next;
        ListNode* pre = start->next;
        ListNode* cur = pre->next;
        ListNode* next;
        // int i = n-m;//此时m已经为0！！！！！直接把 m 做循环变量不够 pure 啊。pure function 是不改变任何输入的函数，所以是线程安全的，pure function 也是函数式编程的精髓
        // while (i-- && cur->next) {/wrong!!!
        //     next = cur->next;
        //     cur->next = pre;
        //     pre = cur;
        //     cur = next;
        // }
        for (int i = m; i < n; ++i) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        (start->next)->next = cur;
        start->next = pre;
        return dummy->next;
    }
};
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy;
        for (int i = 1; i <= m - 1; ++i) cur = cur->next;
        ListNode* pre, *last, *front;
        pre = cur;
        last = pre->next;
        for (int i = m; i <= n; ++i) {
            cur = pre->next;
            pre->next = cur->next;
            cur->next = front;
            front = cur;
        }
        last->next = pre->next;
        pre->next = front;
        return dummy->next;
    }
};
int main() {
    int m = 2;
    for (int i = 1; i <= m - 1; ++i) cout <<k<<endl;
    while (--m) {
            cur = cur->next;
        }
}