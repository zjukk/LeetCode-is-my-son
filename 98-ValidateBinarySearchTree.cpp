#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//错误。。不能保证大于左子树上的所有值或者小于右子树上的所有值
class Solution1 {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (root->left && root->val <= (root->left)->val) return false;
        if (root->right && root->val >= (root->right)->val) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
//中序遍历输出,非递归版本
class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        vector<int> v;
        stack<TreeNode*> s;
        int pre, cur;
        pre = LONG_MIN;
        cur = INT_MIN;        
        while (!s.empty() || root != NULL) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                // v.push_back(root->val);
                cur = root->val;
                if (cur <= pre) return false;
                pre = cur;
                s.pop();
                root = root->right;
            }
        }
        // for (int i = 0; i < v.size()-1; ++i) {
        //     if (v[i] >= v[i+1]) return false;
        // }
        return true;
    }
};
//中序遍历输出,递归版本
class Solution2-2 {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        vector<int> v;
        inOrder(root, v);
        for (int i = 0; i < v.size()-1; ++i) {
            if (v[i] >= v[i+1]) return false;
        }
        return true;
    }
    void inOrder(TreeNode* root, vector<int>& v) {
        if (!root) return;
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
    }
};
//利用性质递归
class Solution3 {
public:
    bool isValidBST(TreeNode* root) {
        return process(root, LONG_MIN, LONG_MAX);
    }
    bool process(TreeNode* root, long mn, long mx) {
        if (!root) return true;
        if (root->val <= mn || root->val >= mx) return false;
        return process(root->left, mn, root->val) && process(root->right, root->val, mx);
        
    }
};
//树形DP，存在问题
class Solution4 {
public:
struct returnData {
    bool isValid;
    int min;
    int max;
    returnData(bool isValid, int min, int max) : isValid(isValid), min(min), max(max) {} 
};
    bool isValidBST(TreeNode* root) {
        bool flag;
        flag = process(root).isValid;
        return flag;
    }
    returnData process(TreeNode* root) {
        if (root == NULL) 
            return returnData(true, LONG_MAX, LONG_MIN); //考虑到int的边界条件 所以用long
        if (root->left == NULL && root->right == NULL) return returnData(true, root->val, root->val);
        returnData left = process(root->left);
        returnData right = process(root->right);
        bool isV;
        if (!left.isValid || !right.isValid) isV = false;
        else if (root->val > left.max && root->val < right.min) {
            isV = true;
        } else isV = false;
        int minm, maxm;
            minm = min(left.min, root->val);
            maxm = max(right.max, root->val);
        return returnData(isV, minm, maxm);
    }
};
//[-2147483648,null,2147483647]
int main() {
    Solution2 s;
    TreeNode* head = new TreeNode(0);
    cout << s.isValidBST(head);
}