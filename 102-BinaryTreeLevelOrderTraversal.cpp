#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        while (!q.empty()) {
            vector<int> cur;
            int size = q.size();//事先把该层元素的个数记录下来
            for (int i = 0; i < size; ++i) {//利用循环来遍历该层元素，放到容器中去,直到遍历完该层元素后，重新计算queue中的元素个数，即是下一层元素的个数
                node = q.front();
                q.pop();
                cur.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(cur);
        }
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        bfs(res, root, 0);
        return res;
    }
    void bfs(vector<vector<int>>& res, TreeNode* root, int level) {
        if (!root) return;//递归终止条件
        if (level == res.size()) res.push_back({});//level递增，res需要增加一层，确保该level下的所有元素可以放在该层容器中
        res[level].push_back(root->val);
        bfs(res, root->left, level+1);
        bfs(res, root->right, level+1);
    }
};
int main() {
    vector<vector<int>> res;
    cout << res.size();
}