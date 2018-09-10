#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        TreeNode* node;
        q.push(root);
        bool fromLeft = true;
        while (!q.empty()) {
            vector<int> cur;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                node = q.front();
                q.pop();
                if (fromLeft)
                cur.push_back(node->val);
                else
                cur.insert(cur.begin(),node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            fromLeft = !fromLeft;
            res.push_back(cur);
        }
        return res;
    }
};
//
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        bfs(res, root, 0, true);
        return res;
    }
    void bfs(vector<vector<int>>& res, TreeNode* root, int level, bool fromLeft) {
        if (!root) return;
        if (level == res.size()) res.push_back({});
        if (fromLeft) res[level].push_back(root->val);
        else res[level].insert(res[level].begin(), root->val);
        bfs(res, root->left, level+1, !fromLeft);
        bfs(res, root->right, level+1, !fromLeft);
    }
};
//利用栈
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<int> out;
        s1.push(root);
        TreeNode* node;
        while (!s1.empty() || !s2.empty()) {
            while (!s1.empty()) {
                node = s1.top();
                s1.pop();
                out.push_back(node->val);
                if(node->left) s2.push(node->left);
                if(node->right) s2.push(node->right);
            }
            if (!out.empty()) res.push_back(out);
            out.clear();
            while (!s2.empty()) {
                node = s2.top();
                s2.pop();
                out.push_back(node->val);
                if(node->right) s1.push(node->right);
                if(node->left) s1.push(node->left);
            }
            if (!out.empty()) res.push_back(out);
            out.clear();
        }
        return res;
    }
};