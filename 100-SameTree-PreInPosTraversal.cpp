#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL) {
            if (q == NULL) return true;
            else return false;
        }
        if (q == NULL) {
            if (p == NULL) return true;
            else return false;
        }
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if ((p && !q) || (!p && q) || (p->val != q->val)) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
//前序遍历 先压右孩子再压左孩子。非递归版本
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if ((p && !q) || (!p && q) || (p->val != q->val)) return false;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(p);
        s2.push(q);
        while (!s1.empty() && !s2.empty()) {
            p = s1.top();
            q = s2.top();
            s1.pop();s2.pop();
            if (p->val != q->val) return false;
            if (p->right) s1.push(p->right);
            if (q->right) s2.push(q->right);
            if (s1.size() != s2.size()) return false;
            if (p->left) s1.push(p->left);
            if (q->left) s2.push(q->left);
            if (s1.size() != s2.size()) return false;
        }
        return true;
    }
};
//中序遍历
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if ((p && !q) || (!p && q) || (p->val != q->val)) return false;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        while (!s1.empty() && !s2.empty() || (p != NULL && q != NULL)) {
            if (p && q) {
                s1.push(p);
                s2.push(q);
                p = p->left;
                q = q->left;               
            } else {
                if ((p && !q) || (q && !p)) return false;
                p = s1.top();
                s1.pop();
                q = s2.top();
                s2.pop();
                if (p->val != q->val) return false;
                p = p->right;
                q = q->right;
            }
        }
        return true;
    }
};
//后序遍历
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if ((p && !q) || (!p && q) || (p->val != q->val)) return false;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(p);
        s2.push(q);
        TreeNode* c1 = NULL;
        TreeNode* c2 = NULL;
        while (!s1.empty() && !s2.empty()) {
            c1 = s1.top();
            c2 = s2.top();
            if (c1->left != NULL && c2->left != NULL && p != c1->left && 
            p != c1->right && q != c2->left && q != c2->right) {
                s1.push(c1->left);
                s2.push(c2->left);
            } else if (c1->right != NULL && c2->right != NULL )
        }
        return true;
    }
};
public static void posOrderUnRecur2(Node h) {
		System.out.print("pos-order: ");
		if (h != null) {
			Stack<Node> stack = new Stack<Node>();
			stack.push(h);
			Node c = null;
			while (!stack.isEmpty()) {
				c = stack.peek();
				if (c.left != null && h != c.left && h != c.right) {
					stack.push(c.left);
				} else if (c.right != null && h != c.right) {
					stack.push(c.right);
				} else {
					System.out.print(stack.pop().value + " ");
					h = c;//h用来记录被弹出的c，防止被重复压入栈中
				}
			}
		}
		System.out.println();
	}