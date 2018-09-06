#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<bool> visited(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        vector<int> cur = {};
        dfs2(candidates, target, 0, cur, visited, ans);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
    void dfs(vector<int>& candidates, int target, int start, vector<int>& cur, vector<bool>& visited, set<vector<int>>& ans) {
        if (target < 0) return;
        if (target == 0) {
            ans.insert(cur);
        } else {
            for (int i = start; i < candidates.size(); i++) {
                if (!visited[i]) {
                    cur.push_back(candidates[i]);
                    visited[i] = true;
                    dfs(candidates, target - candidates[i], i, cur, visited, ans);
                    cur.pop_back();
                    visited[i] = false;
                }
            }
        }
    }
//sol2:不需要bool visited 把start+1传入递归函数调用
    void dfs2(vector<int>& candidates, int target, int start, vector<int>& cur, vector<bool>& visited, set<vector<int>>& ans) {
        if (target < 0) return;
        if (target == 0) {
            ans.insert(cur);
        } else {
            for (int i = start; i < candidates.size(); i++) {
                
                    cur.push_back(candidates[i]);
                    //visited[i] = true;
                    dfs(candidates, target - candidates[i], i + 1, cur, visited, ans);
                    cur.pop_back();
                    //visited[i] = false;
                
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> candidates= {10,1,2,7,6,1,5};
    vector<vector<int>> ans= s.combinationSum2(candidates, 8);
    for (auto &a : ans)
        for (int i : a) {
            cout << i;
        }
}