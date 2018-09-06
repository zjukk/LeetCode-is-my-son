#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int> > s;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        dfs(s, cur, nums, 0);
        vector<vector<int> > res(s.begin(), s.end());
        return res;
    }
    void dfs(set<vector<int> >& s, vector<int>& cur, vector<int>& nums, int level) {
        s.insert(cur);
        if (level == nums.size()) return;
        for (int i = level; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            dfs(s, cur, nums, i+1);
            cur.pop_back();
        }
    }
};
int main() {
    Solution s;
    vector<int> nums = {4,4,4,1,4};
    vector<vector<int>> res = s.subsetsWithDup(nums);
    for (auto v : res) {
        for (int i : v) 
            cout << i;
        cout << endl;
    }
}