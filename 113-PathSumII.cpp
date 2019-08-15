#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> out;
        helper(root, sum, out, res);
        return res;
    }
    void helper(TreeNode* node, int sum, vector<int>& out, vector<vector<int>>& res) {
        if (!node) return;
        out.push_back(node->val);
        if (sum == node->val && !node->left && !node->right) {
            res.push_back(out);
        }
        helper(node->left, sum - node->val, out, res);
        helper(node->right, sum - node->val, out, res);
        out.pop_back();
    }
};
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, cur, root, sum);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& cur, TreeNode* root, int sum) {
        if (!root) return;
        cur.push_back(root->val);
        if (!root->left && !root->right && sum == root->val) {
            res.push_back(cur);
            // return;此处不可以有return因为还要把当前的root pop掉返回上一级！！！
        }
        // if (sum <= root->val) return;
        dfs(res, cur, root->left, sum-root->val);//(*1)
        dfs(res, cur, root->right, sum-root->val);//(*2)
        cur.pop_back();//pop掉的是当前的root (1)(2)中的cur仍然是相同的
    }
};
//利用vector实现中序遍历 迭代法
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<TreeNode*> v;
        int vals;
        TreeNode* cur = root, *pre = NULL;//pre用来保存上一个到达过的元素
        while (cur || !v.empty()) {
            while (cur) {
                v.push_back(cur);   
                vals += cur->val;
                cur = cur->left;
            }
            cur = v.back();
            if (!cur->left && !cur->right && vals == sum) {
                vector<int> tmp;
                for (auto a : v) {
                    tmp.push_back(a->val);
                }
                res.push_back(tmp);
            }
            if (cur->right && cur->right != pre) cur = cur->right;//我有右孩子并且未到达则往右走，否则返回上一级
            else {
                pre = cur;
                v.pop_back();
                vals -= cur->val;
                cur = NULL;//此处cur必须为NULL，不能为v.back() 在while后面实现重新赋值
            }
        }
        return res;
    }
};