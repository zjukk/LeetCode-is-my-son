#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left)
            return minDepth(root->right) + 1;
        else if (!root->right)
            return minDepth(root->left) + 1;
        else 
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        // if (minDepth(root->left) != 0 && minDepth(root->right) != 0)
        //     return min(minDepth(root->left), minDepth(root->right)) + 1;
        // else 
        //     return max(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        if (root->left == NULL) return minDepth(root->right) + 1;
        else if (root->right == NULL) return minDepth(root->left) + 1;
        else return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};