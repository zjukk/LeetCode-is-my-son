#include <iostream>

using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        process(root, res);
        return res;
    }
    //返回以当前节点为终点的最大路径和
    int process(TreeNode* root, int& res) {
        if (!root) return 0;
        int left = max(process(root->left, res), 0);//排除负数
        int right = max(process(root->right, res), 0);
        res = max(res, left + right + root->val);
        return max(left, right) + root->val;
    }
};