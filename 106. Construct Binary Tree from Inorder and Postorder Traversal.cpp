#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) return NULL;
        int n = inorder.size();
        TreeNode* root = new TreeNode(postorder[n-1]);
        int gen = 0;
        for (int i = 0; i < n; ++i) {
            if (inorder[i] == postorder[n-1]) {
                gen = i;
                break;
            }
        }
        vector<int> li, ri, lp, rp;
        for (int i = 0; i < gen; ++i) {
            li.push_back(inorder[i]);
            lp.push_back(postorder[i]);
        }
        for (int i = gen; i < n-1; ++i) {
            ri.push_back(inorder[i+1]);
            rp.push_back(postorder[i]);
        }
        TreeNode* left = buildTree(li, lp);
        TreeNode* right = buildTree(ri, rp);
        root->left = left;
        root->right = right;
        return root;
    }
};

class Solution2 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    TreeNode* buildTree(vector<int>& inorder, int iLeft, int iRight, vector<int>& postorder, int pLeft, int pRight) {
        if (iLeft > iRight) return NULL;
        TreeNode* root = new TreeNode(postorder[pRight]);
        int i = iLeft;
        for (; i <= iRight; ++i) {
            if (inorder[i] == root->val)
                break;
        }
        root->left = buildTree(inorder,iLeft,i-1,postorder,pLeft,pLeft-iLeft+i-1);
        root->right = buildTree(inorder,i+1,iRight,postorder,pLeft-iLeft+i,pRight-1);
        return root;
    }
};