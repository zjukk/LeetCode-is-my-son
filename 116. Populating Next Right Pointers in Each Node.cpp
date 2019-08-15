#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void connect(TreeLinkNode *root) {
      if (!root) return;
      queue<TreeLinkNode*> q;
      q.push(root);
      while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeLinkNode* cur = q.front();
            q.pop();
            if (i != size - 1) {
                cur->next = q.front();
            } else {
                cur->next = NULL;
            }
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
      }
    }
};
//recursion

class Solution {
public:
    void connect(TreeLinkNode *root) {
      if (!root) return;
      if (root->left && root->right) {
          root->left->next = root->right;
      if (!root->next) root->right->next = NULL;
      else root->right->next = root->next->left;
      connect(root->left);
      connect(root->right);
      }
    }
};