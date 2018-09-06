#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur = {};
        combineDfs(n, k, 0, ans, cur);
        return ans;
    }
    void combineDfs(int n, int k, int level, vector<vector<int>> &ans, vector<int> cur) {
        if (level == k) {
            ans.push_back(cur);
            return;
        }
        for (int i = 1; i <= n; i++) {
            if(cur.size() == 0 || i > cur.back()){
                cur.push_back(i);
                combineDfs(n, k, level + 1, ans, cur);
                cur.pop_back();                
            }

        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> ans = s.combine(4,2);
    for (auto &a : ans){
        for (int i : a) {
            cout << i;
        }
    }
}