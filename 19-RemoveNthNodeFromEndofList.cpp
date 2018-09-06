    #include <iostream>
    #include <algorithm>
    #include <vector>

    using namespace std;
    struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
     };
    ListNode* reverse(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* next =NULL;
        while(cur != NULL) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
     ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* rev = reverse(head);
        ListNode* rec = rev;
        ListNode* pre = NULL;
        if(n == 1) {//special situation
         if(rev->next == NULL){
             return NULL;
         } else {
             return reverse(rev->next);
         }
        }
        while(--n){
            pre = rev;
            rev = rev->next;
        }
        pre->next = rev->next;
        return reverse(rec);
    }
    //delete the L-n+1 th node
     ListNode* removeNthFromEnd2(ListNode* head, int n) {
         ListNode* rec = head;
         ListNode* cur = head;
         int len = 0;
         while(head != NULL){
             len++;
             head = head->next;
         }
         int num = len - n + 1;    
         if (num == 1) {
             return cur->next;
         }
         ListNode* pre = NULL;
         while (--num){
             pre = cur;
             cur = cur->next;
         }
         pre->next = cur->next;//可以只用一个指针进行优化 first.next = first.next.next;
         return rec;
     }
     // 1 pass with 2 pointer
     ListNode* removeNthFromEnd3(ListNode* head, int n) {
         ListNode* dummy = new ListNode(0);
         dummy->next = head;
         ListNode* first = head;
         ListNode* second = head;
         n++;
         while (n--) {
             first = first->next;
         }
         while (first != NULL) {
             first = first->next;
             second = second->next;
         }
         second->next = (second->next)->next;
         return dummy->next;
     }