#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> ans(m, vector<int>(n,0));
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 0) {
                ans[i][0] = 1;
            } else {
                ans[i][0] = 0;
                break;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[0][j] == 0) {
                ans[0][j] = 1;
            } else {
                ans[0][j] = 0;
                break;
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) ans[i][j] = 0;
                else ans[i][j] = ans[i-1][j] + ans[i][j-1];
            }
        }
        return ans[m-1][n-1];
    }
};
int main() {
    Solution s;
    vector<vector<int>> ans;
    vector<vector<int>> obstacleGrid = {{1,0}};//{{0,0,0},{0,1,0},{0,0,0}};
    cout << s.uniquePathsWithObstacles(obstacleGrid);  
}