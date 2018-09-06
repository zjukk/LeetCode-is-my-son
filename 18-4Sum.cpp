#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> cur = {};
        dfs(nums, target, 0, cur, ans);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
    void dfs(vector<int>& nums, int target, int start, vector<int>& cur, set<vector<int>>& ans) {
        if (cur.size() > 4) return;
        if (cur.size() == 4 && target == 0) {
            ans.insert(cur);
        } else {
            for (int i = start; i < nums.size(); i++) {
                    cur.push_back(nums[i]);
                    dfs(nums, target - nums[i], i + 1, cur, ans);
                    cur.pop_back();
            }
        }
    }

    vector<vector<int>> fourSum2(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return {};
        }
        vector<int> cur(4);
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        for (int i = 0; i < nums.size() - 3; i++) {
            cur[0] = nums[i];
            for (int j = i + 1; j < nums.size() - 2; j++) {
                cur[1] = nums[j];
                for (int k = j + 1; k < nums.size() - 1; k++) {
                    cur[2] = nums[k];
                    for (int l = k + 1; l < nums.size(); l++) {
                        cur[3] = nums[l];
                        if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                            ans.insert(cur);
                        }
                    }                
                }
            }
        }
         vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};
int main() {
    Solution s;
    vector<int> nums= {-5,5,4,-3,0,0,4,-2};
    vector<vector<int>> ans= s.fourSum2(nums, 4);
    for (auto &a : ans)
        for (int i : a) {
            cout << i;
        }
}