/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return{};
        vector<int> res;
        stack<TreeNode*> s;
        while (!s.empty() || root) {
            while (root) {
                res.push_back(root->val);
                s.push(root);
                root = root->left;
          }
          root = s.top()->right;
          s.pop();
      }
      return res;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return{};
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            res.push_back(root->val);
            if (root->right) s.push(root->right);
            if (root->left) s.push(root->left);
        }
        return res;
    }
};
