#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> p(m, vector<int>(n));
    p[m-1][n-1] = grid[m-1][n-1];
    for (int i = n-2; i >= 0; i--) {
        p[m-1][i] = p[m-1][i+1] + grid[m-1][i];
    }
    for (int i = m-2; i >= 0; i--) {
        p[i][n-1] = p[i+1][n-1] + grid[i][n-1];
    }
    for (int i = m-2; i >= 0; i--) {
        for (int j = n-2; j >=0; j--) {
            p[i][j] = grid[i][j] + min(p[i+1][j], p[i][j+1]);
        }
    }
    return p[0][0];
}
int main() {
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << minPathSum(grid);
}