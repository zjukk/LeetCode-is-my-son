#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string cur;
        vector<string> ans;
        vector<bool> visited(10,false);
        dfs(cur, ans, visited, 0, n, k);
        return ans[k-1];
    }
    void dfs(string& cur, vector<string>& ans, vector<bool>& visited, int level, int n, int k) {
        //if(cnt == k && level == n) {ans = cur;return;}
        if (level == n) {ans.push_back(cur);return;}
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                cur +=  ('0' + i);
                visited[i] = true;
                dfs(cur, ans, visited, level+1, n, k);
                cur.pop_back();
                visited[i] = false;
            }
        }
    }
    //sol2:
    string getPermutation2(int n, int k) {
        string res;
        string num = "123456789";
        //用vector表示阶乘
        vector<int> f(n,1);
        for (int i = 1; i < n; ++i) f[i] = f[i-1]*i;
        --k;
        for (int i = n-1; i >= 0; --i) {
            int j = k / f[i];//商
            k %= f[i];//余数
            res.push_back(num[j]);
            cout << "j: " << j << "k: " << k << "res: " << res << endl;
            num.erase(j,1);
        return res;
    }
};
int main() {
    Solution s;
    cout << s.getPermutation2(3,2);
}