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
class Solution {
public:
    void connect(TreeLinkNode *root) {
      if (!root) return;
      TreeLinkNode* p = root->next;
      //用p记录第一个可以被指向的结点
      while (p) {
          if (p->left) {
              p = p->left;
              break;
          } else if (p->right) {
              p = p->right;
              break;
          } else p = p->next;
      }
      if (root->right) root->right->next = p;
      if (root->left) root->left->next = root->right ? root->right : p; 
      connect(root->right);//这里必须先处理右孩子，因为左孩子受到右孩子的影响，
      connect(root->left);
    }
};
