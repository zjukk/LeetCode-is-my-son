#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        bool fromLeft = true;
        while (!q.empty()) {
            vector<int> tmp;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                node = q.front();
                q.pop();
                if (fromLeft)
                tmp.push_back(node->val);
                else 
                tmp.insert(tmp.begin(),node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            fromLeft = !fromLeft;
            res.push_back(tmp);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        bfs(res,root,0);
        return res;
    }
    void bfs(vector<vector<int>> res, TreeNode* root, int level, bool fromLeft) {
        if (!root) return NULL;
        if (level = res.size()) res.push_back({});
        if (fromLeft) res[level].push_back(root->val);
        else res[level].insert(res[level].begin(),root->val);
        if (root->left) bfs(res,root->left,level+1,!fromLeft);
        if (root->right) bfs(res,root->right,level+1,!fromLeft);
    }
};