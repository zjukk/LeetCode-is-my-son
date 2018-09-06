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
    ListNode* swapPairs(ListNode* head) {
        ListNode* ans = head;
        while (head != NULL && head->next != NULL) {
            swap(head->val, (head->next)->val);
            head = (head->next)->next;
        }
        return ans;
    }
};