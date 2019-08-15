#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (nums.empty()) return {};
        TreeNode* head = new TreeNode(nums[(n-1)/2]);
        vector<int> l(nums.begin(),nums.begin()+(n-1)/2);
        vector<int> r(nums.begin()+(n-1)/2)+1, nums.end());
        TreeNode* left = sortedArrayToBST(l);
        TreeNode* right = sortedArrayToBST(r);
        head->left = left;
        head->right = right;
        return head;
    }
};
