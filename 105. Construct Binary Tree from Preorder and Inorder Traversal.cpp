#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return NULL;
        if (preorder.size() == 1) return new TreeNode(preorder[0]);//返回值要加new!!!因为返回类型是指针
        TreeNode* root = new TreeNode(preorder[0]);
        int gen = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == preorder[0]) {
                gen = i; break;
            }
        }
        vector<int> lp, li, rp, ri;
        for (int i = 0; i < gen; ++i) {
            li.push_back(inorder[i]); 
            lp.push_back(preorder[i+1]);
        }
        for (int i = gen+1; i < inorder.size(); ++i) {
            ri.push_back(inorder[i]);
            rp.push_back(preorder[i]);
        }
        TreeNode* left = buildTree(lp, li);
        TreeNode* right = buildTree(rp, ri);
        root->left = left;
        root->right = right;
        return root;
    }
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& preorder, int pLeft, int pRight, vector<int>& inorder, int iLeft, int iRight) {
        if (pLeft > pRight) return NULL;
        TreeNode* root = new TreeNode(preorder[pLeft]);
        int i;//这个i是从iLeft开始计算的 而不是从0开始计算的,因此它是一个相对于iLeft的坐标
        for (i = iLeft; i < iRight; ++i) {
            if (inorder[i] == preorder[pLeft])
            break;
        }
        root->left = buildTree(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft, i-1);
        root->right = buildTree(preorder, pLeft + i - iLeft + 1, pRight, inorder, i + 1, iRight);
        //wrong of i
        // root->left = buildTree(preorder, pLeft + 1, i, inorder, iLeft, i-1);
        // root->right = buildTree(preorder, i, pRight, inorder, i + 1, iRight);
        return root;
    }
};