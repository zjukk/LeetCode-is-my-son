#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty()) return {};
        set<vector<int>> ans;
        vector<int> cur{};
        vector<bool> visited(nums.size(), false);
        dfs(nums, 0, cur, ans, visited);

        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
    void dfs(vector<int>& nums, int level, vector<int>& cur, set<vector<int>>& ans, vector<bool> visited) {
        if (level == nums.size()) {
            ans.insert(cur);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            cur.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, level + 1, cur, ans, visited);
            cur.pop_back();
            visited[i] = false;
        }
    }
};
//sol2:
class Solution2 {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        vector<int> out;
        vector<int> visited(num.size(), 0);
        sort(num.begin(), num.end());
        permuteUniqueDFS(num, 0, visited, out, res);
        return res;
    }
    void permuteUniqueDFS(vector<int> &num, int level, vector<int> &visited, vector<int> &out, vector<vector<int> > &res) {
        if (level >= num.size()) res.push_back(out);
        else {
            for (int i = 0; i < num.size(); ++i) {
                if (visited[i] == 0) {
                    if (i > 0 && num[i] == num[i - 1] && visited[i - 1] == 0) continue;
                    visited[i] = 1;
                    out.push_back(num[i]);
                    permuteUniqueDFS(num, level + 1, visited, out, res);
                    out.pop_back();
                    visited[i] = 0;
                }
            }
        }
    }
};
//sol3:
class Solution3 {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        permute(nums, 0, res);
        return vector<vector<int>> (res.begin(), res.end());
    }
    void permute(vector<int> &nums, int start, set<vector<int>> &res) {
        if (start >= nums.size()) res.insert(nums);
        for (int i = start; i < nums.size(); ++i) {
            if (i != start && nums[i] == nums[start]) continue;
            swap(nums[i], nums[start]);
            permute(nums, start + 1, res);
            swap(nums[i], nums[start]);
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,2};
    vector<vector<int>> ans = s.permuteUnique(nums);
    for (auto &a : ans)
        for (int i : a) {
            cout << i;
        }
    
}