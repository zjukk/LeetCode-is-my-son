#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n <= 0) return{}; 
        vector<vector<string> > ans;
        vector<int> pos(n, -1);
        dfs(pos, 0, ans);
        return ans;
    }
    void dfs(vector<int>& pos, int row, vector<vector<string> >& ans) {
        int n = pos.size();
        if (row == n) {
            vector<string> out(n,string(n, '.'));
            for (int i = 0; i < n; i++) {
                out[i][pos[i]] = 'Q';
            }
            ans.push_back(out);
        } else {
            for (int col = 0; col < n; ++col) {
            if (isValid(pos, row, col)) {
                pos[row] = col;
                dfs(pos, row + 1, ans);
                pos[row] = -1;
            }
            }
        }
        
    }
    bool isValid(vector<int>& pos, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (col == pos[i] || abs(row - i) == abs(col - pos[i]))
            return false;
        }
        return true;
    }
};
int main() {
    Solution s;
    vector<vector<string>> ans = s.solveNQueens(5);
    // cout << ans.size() << endl;
    int cnt = 0;
    for (auto a : ans) {
        for (auto i : a){
            cout << i << endl;
            if(++cnt%5 == 0)
            cout << endl;
        }   
    }
}