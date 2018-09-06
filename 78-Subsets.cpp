#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<vector<int> > ans;
        vector<int> cur{};
        dfs(ans, cur, nums, 0);
        return ans;
    }
    void dfs(vector<vector<int> >& ans, vector<int>& cur, vector<int>& nums, int level) {
        ans.push_back(cur);
        for (int i = level; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            dfs(ans, cur, nums, i + 1);//传递的是i+1而非level+1;
            cur.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {1,2,3};
    Solution s;
    vector<vector<int> > ans = s.subsets(nums);
    for (auto v :ans) {
        for (auto i : v)
            cout << i;
        cout << endl;
    }
}