#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
//recursion
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        if (root->left) flatten(root->left);
        if (root->right) flatten(root->right);
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode* cur = root;
        while (cur->right) {
            cur = cur->right;
        }
        cur->right = tmp;
    }
};
//iteration1
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode* lr = cur->left;
                cur->right = lr;
                while (lr->right) {
                    lr = lr->right;
                }
                lr->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
                cur = cur->right;
        }
    }
};
//iteration2 stack版本中序遍历
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> s;
        if(root->right) s.push(root->right）;
        if(root->left) s.push(root->left);
        TreeNode* cur = root;
        while (!s.empty()) {
            TreeNode* tmp = s.top();
            s.pop();
            cur->left = NULL;
            cur->right = tmp;
            cur = cur->right;
            if(tmp->right) s.push(tmp->right）;
            if(tmp->left) s.push(tmp->left);
        }
    }
};
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *t = s.top(); s.pop();
            if (t->left) {
                TreeNode *r = t->left;
                while (r->right) r = r->right;
                r->right = t->right;
                t->right = t->left;
                t->left = NULL;
            }
            if (t->right) s.push(t->right);//此时t->right已经是前面的t->left了
        }
    }
};