#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

class Solution {
private:
    int ans;
public:
    int totalNQueens(int n) {
        if (n == 0) return 0;
        vector<int> pos(n, -1);
        dfs(pos, 0);
        return ans;
    }
    void dfs(vector<int>& pos, int row) {
        int n = pos.size();
        if (row == n) {
            ans++;
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (isValid(pos, row, col)) {
                pos[row] = col;
                dfs(pos, row+1);
                pos[row] = -1;
            }
        }
    }
    bool isValid(vector<int>& pos, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (pos[i] == col || abs(i - row) == abs(col - pos[i]))
            return false;
        }
        return true;
    }
};
int main() {
    Solution s;
    cout << s.totalNQueens(4) << " " << s.totalNQueens(5) << s.totalNQueens(4);
}