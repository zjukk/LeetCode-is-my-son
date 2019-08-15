#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//Time Limit Exceeded
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
//itoration
class Solution {
public:
    int sumNumbers(TreeNode* root) {
       if (!root) return 0;
       stack<TreeNode*> s;
       int cur = 0;
       int sum = 0;
       TreeNode* pre = NULL;
       while (!s.empty() || root) {
           while (root) {
               s.push(root);
               cur = cur * 10 + root->val;
               root = root->left;
           }
           root = s.top();
           if (root->right && root->right != pre) {
               root = root->right;
           } else if (!root->right && !root->left) {
               sum += cur;
               s.pop();
               cur /= 10;
               pre = root;
               root = NULL;
           } else {
               s.pop();
               cur /= 10;
               pre = root;
               root = NULL;
           }
       }
       return sum;
    }
};
//recursion
class Solution2 {
public:
    int sumNumbers(TreeNode* root) {
        return process(root, 0);
    }
    int process(TreeNode* root, int sum) {
        if (!root) return 0;
        sum = sum*10 + root->val;
        if (!root->left && !root->right) return sum;//到达叶节点
        else return process(root->left, sum) + process(root->right, sum);//未到达叶节点
    }
};
int main() {
    TreeNode* n1 = new TreeNode(1);
    n1->left = new TreeNode(2);
    n1->right = new TreeNode(3);
    // n1->left->left = new TreeNode(3);
    Solution2 s;
    cout << s.sumNumbers(n1);
}