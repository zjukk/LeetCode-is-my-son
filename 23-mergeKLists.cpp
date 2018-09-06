#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <limits>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

public:
//sol1:Brute force
    ListNode* mergeLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode(0);
        ListNode* res = ans;
        vector<int> v;
        for (int i = 0; i < lists.size(); i++) {
            while (lists[i] != NULL) {
                v.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        stable_sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            ans->next = new ListNode(v[i]);
            ans = ans->next;
        }
        return res->next;
    }

    //sol2:recursion divide&conquer
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
    ListNode* process(vector<ListNode*>& lists, int L, int R) {
        int mid = (L+R)/2;
        ListNode* leftNode = process(lists, L, mid);
        ListNode* rightNode = process(lists, mid+1, right);
        return mergeTwoLisrs(leftNode,rightNode);
    }
    ListNode* mergeLists2(vector<ListNode*>& lists) {
        return process(lists, 0, lists.size() - 1);
    }
    //sol3:
    ListNode* mergeKLists3(vector<ListNode*>& lists) {
        if(lists.size() == 0)
        return NULL;
        if (lists.size() == 1)
        return lists[0];
        ListNode* ans = mergeTwoLists(lists[0], lists[1]);
        for (int i = 2; i < lists.size(); i++) {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }