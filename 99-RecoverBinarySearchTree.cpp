#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <stack>
using namespace std;

//中序， 空间复杂度O(N)
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> list;
        vector<int> vals;
        inOrder(root, list, vals);
        sort(vals.begin(), vals.end());
        for (int i = 0, j = 0; i < vals.size(); ++i,++j) {
            list[i]->val = vals[i];
        }
    }
    void inOrder(TreeNode* root, vector<TreeNode*>& list, vector<int>& vals) {
        if (!root) return;
        inOrder(root->left, list, vals);
        list.push_back(root);
        vals.push_back(root->val);
        inOrder(root->right, list, vals);
    }
};
//Morris(中序)遍历 空间复杂度O(1)
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* cur1, *cur2, *first, *second, *pre;
        cur1 = root; cur2 = NULL; first = NULL; second = NULL; pre = NULL;
        while (cur1) {
            cur2 = cur1->left;
            if (cur2) {
                while (cur2->right && cur2->right != cur1) {
                    cur2 = cur2->right;
                }
                if (cur2->right == NULL) {
                    cur2->right = cur1;
                    cur1 = cur1->left;
                    continue;
                } else {
                    cur2->right = NULL;
                }
            }
            if (pre && pre->val > cur1->val) {
                if (!first) first = pre;//first记录第一个错误的位置
                second = cur1;//second记录最后一个错误的位置
            }
            pre = cur1;
            cur1 = cur1->right;
        }
        if (first && second) swap(first->val, second->val);
    }
};