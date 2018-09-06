#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
ListNode *detectCycle(ListNode *head) {
    if(head == NULL || head->next == NULL || (head->next)->next == NULL) return NULL;
    ListNode* slow = head->next;
    ListNode* fast = (head->next)->next; 
    while (fast != slow) {
        if(fast->next == NULL || (fast->next)->next == NULL) return NULL;
        fast = (fast->next)->next;
        slow = slow->next;
    }
    if (fast == NULL) return NULL;
        fast = head;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
    return fast;
}