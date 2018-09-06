#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<vector<int>> ans;
        vector<int> cur = {};
        permuteDfs(nums, ans, cur, 0);
        return ans;
    }
        void permuteDfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& cur, int level) {
            if (level == nums.size()) {
                ans.push_back(cur);
                return;
            }
            for (int i = 0; i < nums.size(); i++) {
                if(cur.empty() || find(cur.begin(), cur.end(), nums[i]) == cur.end()) {
                    cur.push_back(nums[i]);
                    permuteDfs(nums, ans, cur, level+1);
                    cur.pop_back();
                }
            }
        }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = s.permute(nums);
    for (auto a : ans) {
        for (auto i : a)
        cout << i;
    }
}