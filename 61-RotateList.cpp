#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode* start = new ListNode(-1);
        start->next = head;
        ListNode* cur = head;
        int n = 1;
        while (cur->next != NULL) {
            ++n;
            cur = cur->next;
        }
        ListNode* last = cur;
        k %= n;
        if (k == 0) return head;//容易漏， otherwise cur最终指向了NULL
        int j = n - k;
        ListNode* pre = NULL;
        ListNode* next = NULL;
        cur = head;
        while (j--) {
            next = cur->next;
            pre = cur;
            cur = cur->next;
        }
        pre->next = NULL;
        last->next = start->next;
        start->next = cur;
        return start->next;
    }
};