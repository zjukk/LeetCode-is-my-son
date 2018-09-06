#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()) return {};
        vector<vector<int>> ans;
        vector<int> cur = {};
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, cur, ans);
        return ans;
    }
    void dfs(vector<int>& candidates, int target, int start, vector<int>& cur, vector<vector<int>>& ans) {
        if (target < 0) return;
        if (target == 0) ans.push_back(cur);
        else {
            for (int i = start; i < candidates.size(); i++) {
                cur.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], i, cur, ans);
                cur.pop_back();
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> candidates= {2,3,5};
    vector<vector<int>> ans= s.combinationSum(candidates, 8);
    for (auto &a : ans)
        for (int i : a) {
            cout << i;
        }
}