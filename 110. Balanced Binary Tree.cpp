#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (isBalanced(root->left) && isBalanced(root->right)) {
            if (abs(height(root->left) - height(root->right)) < 2)
                return true;
        }
        return false;
    }
    int height(TreeNode* root) {
        if (!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
};