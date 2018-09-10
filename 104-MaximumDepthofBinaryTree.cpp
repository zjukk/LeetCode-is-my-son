#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
class Solution {
public:
    int maxDepth(TreeNode* root) {
        vector<int> res;
        bfs(res, 0, root);
        sort(res.begin(), res.end());
        return res.back();
    }
    void bfs(vector<int>& res, int depth, TreeNode* root) {
        if (!root) {
            res.push_back(depth);
            return;
        }
        bfs(res, depth+1, root->left);
        bfs(res, depth+1, root->right);
    }
};

class Solution {
public:
struct returnData{
    int height;
    returnData(int h) : height(h){}
};
    int maxDepth(TreeNode* root) {
        return process(root).height;
    }
    returnData process(TreeNode* root) {
        if (!root) return returnData(0);
        returnData left = process(root->left);
        returnData right = process(root->right);
        int h = max(left.height, right.height) + 1;
        return returnData(h);
    }
};