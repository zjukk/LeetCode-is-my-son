#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <limits>
using namespace std;
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* res = ans;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                ans->next = l1;
                l1 = l1->next;
                ans = ans->next;
            } else {
                ans->next = l2;
                l2 = l2->next;
                ans = ans->next;
            }
        }
        while (l1 != NULL) {
            ans->next = l1;
            l1 = l1->next;
            ans = ans->next;
        }
        while (l2 != NULL) {
            ans->next = l2;
            l2 = l2->next;
            ans = ans->next;
        }
        return res->next;
    }