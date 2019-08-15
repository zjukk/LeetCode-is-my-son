//Sol1:
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return{};
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur = NULL;
        TreeNode* pre = root;
        s.push(root);
        while (!s.empty()) {
            cur = s.top();
            if (cur->left && cur->left != pre && cur->right != pre)  {//第三次到达当前节点时，此时pre = cur->right，不执行
                cur = cur->left;
            } else if (cur->right && cur->right != pre) {//第二次到达当前节点，此时pre = cur->left，执行
                cur = cur->right;
            } else {
                res.push_back(cur->val);
                s.pop();
                pre = cur;
            }
        }
        return res;
    }
};
//Sol2:
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return{};
        vector<int> res;
        stack<TreeNode*> s;
        while (!s.empty() || root) {
            while (root) {
                res.push_back(root->val);
                s.push(root);
                root = root->right;
            }
            root = s.top()->left;
            s.pop();
        }
        vector<int> ans;
        for (int i = res.size() - 1; i >= 0; --i) {
            ans.push_back(res[i]);
        }
        return ans;
    }
};

vector<int> postorderTraversal(TreeNode* root) {
    if (!root) return{};
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* cur = root;
    TreeNode* visited = NULL;
    while (!s.empty() || cur) {
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        if (!cur->right || cur->right == visited) {
            res.push_back(cur->val);
            s.pop();
            visited = cur;
            cur = NULL;
        } else {
            cur = cur->right;
        }
    }
    return res;
}