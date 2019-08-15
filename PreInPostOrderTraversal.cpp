#include <iostream>
#include <stack>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  //Recursion version
  void PreOrderRecur(TreeNode* root) {
      if (!root) return;
      cout << root->val;
      PreOrderRecur(root->left);
      PreOrderRecur(root->right);
  }
  void InOrderRecur(TreeNode* root) {
      if (!root) return;
      InOrderRecur(root->left);
      cout << root->val;
      InOrderRecur(root->right);
  }
  void PostOrderRecur(TreeNode* root) {
      if (!root) return;
      PostOrderRecur(root->left);
      PostOrderRecur(root->right);
      cout << root->val;
  }
  //non-recursion
  //PreOrder
  void PreOrderUnRecur(TreeNode* root) {
      if (!root) return;
      stack<TreeNode*> s;
      while (!s.empty() || root) {
          while (root) {
              cout << root->val;
              s.push(root);
              root = root->left;
          }
          root = s.top()->right;
          s.pop();
      }
  }
  void PreOrderUnRecur2(TreeNode* root) {
      if (!root) return;
      stack<TreeNode*> s;
      s.push(root);
      while (!s.empty()) {
          root = s.top();
          s.pop();
          cout << root->val;
          if (root->right) s.push(root->right);
          if (root->left) s.push(root->left);
      }
  }
//InOrder
void InOrderUnRecur(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> s;
    while (!s.empty() || root) {
        while (root) {
            s.push(root);
            root = root->val;
        }
        root = s.top();
        cout << root->val;//preorder和inorder的差别只在于输出的位置不同
        s.pop();
        root = root->right;
    }
}
//***postTraversal
//vesion1 record the visit status..Time Limit Exceeded???
//ToRevise
void PostOrderUnRecur(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> s;
    TreeNode* cur;
    TreeNode* pre = root;
    s.push(root);
    while (!s.empty()) {
        cur = s.top();
        if (cur->left && cur->left != pre && cur->right != pre)  {//第三次到达当前节点时，此时pre = cur->right，不执行
            cur = cur->left;
        } else if (cur->right && cur->right != pre) {//第二次到达当前节点，此时pre = cur->left，执行
            cur = cur->right;
        } else {
            cout << cur->val;
            s.pop();
            pre = cur;
        }
    }
}
//vesion2 根右左->左右根(反转) 每到达一个节点，按照root, root->right, root->left的顺序压入help栈中，最后从栈中弹出
void PostOrderUnRecur(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> s;
    stack<TreeNode*> help;
    s.push(root);
    while (!s.empty()) {
        root = s.top();
        s.pop();
        help.push(root);
        if (root->left) s.push(root->left);
        if (root->right) s.push(root->right); 
    }
    while (!help.empty()) {
        cout << help.top()->val;
        help.pop();
    }
}
//version 3
void PostOrderUnRecur(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> s;
    TreeNode* cur = root;
    TreeNode* visited = NULL;
    while (!s.empty() || cur) {
        s.push(cur);
        cur = cur->left;
    }
    cur = s.top();
    //右孩子不存在或者右孩子已经访问过了，打印当前结点
    if (!cur->right || cur->right == visited) {
        cout << cur->val;
        s.pop();//返回
        visited = cur;
        cur = NULL;//cur需要手动置为空，然后在上面的代码中取堆顶元素进行重新赋值，此处cur不能赋值为s.top(),避免再次进入左子树
    } else {
        cur = cur->right;
    }
}


 