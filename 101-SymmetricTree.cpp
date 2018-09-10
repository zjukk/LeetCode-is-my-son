#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <stack>
#include <queue>
using namespace std;
//递归recursion
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right) {//转化到左右两个节点上的递归。我们需要的是比较两颗子树对应的左右节点，而非单一树上的左右节点
        if (!left && !right) return true;
        if ((left && !right) || (!left && right)) return false;
        if (left->val != right->val) return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};
//iteration using queue 层序遍历levelorderTraversal
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root->left);
        q2.push(root->right);
        TreeNode* node1;
        TreeNode* node2;
        while (!q1.empty() && !q2.empty()) {
            node1 = q1.front();
            node2 = q2.front();
            q1.pop();
            q2.pop();
            if ((node1 && !node2) || (!node1 && node2)) return false;
            if (node1 && node2) {
                if (node1->val != node2->val) return false;
                q1.push(node1->left);
                q1.push(node1->right);
                q2.push(node2->right);
                q2.push(node2->left);
            }
            
        }
        return true;
    }
};