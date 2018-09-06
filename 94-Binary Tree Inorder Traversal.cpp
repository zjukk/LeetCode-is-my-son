#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL)
        return ans;
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);
        ans = left;
        ans.push_back(root->val);
        for (int a : right) {
            ans.push_back(a->val);
        }
        return ans;
    }
    vector<int> inorderTraversal(TreeNode* root) { 
        vector<int> ans;
        if (root == NULL)
        return ans;
        stack<TreeNode*> s;
        while (!s.empty() || root != NULL) {
            if(root != NULL){
                s.push(root);
                root = root->left;
            } else {
                ans.push_back(s.top()->val);
                s.pop();
                root = s.top()->right;
            }

        }
        return ans;
    }