#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size() - 1;
        int n = grid[0].size() - 1;
        int res = 0;
        vector<vector<bool>> visited(m+1, vector<bool>(n+1, false));
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ++res;
                    dfs(grid, visited, m, n, i, j);
                }
            }
        }
        return res;
    }
    //dfs
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int m, int n, int i, int j) {
        if (i < 0 || i > m || j < 0 || j > n || visited[i][j] || grid[i][j] != '1') return;
        visited[i][j] = true;
        dfs(grid, visited, m, n, i-1, j);
        dfs(grid, visited, m, n, i, j-1); 
        dfs(grid, visited, m, n, i+1, j);
        dfs(grid, visited, m, n, i, j+1);
    }
    //bfs
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int m, int n, int i, int j) {
        visited[i][j] = true;
        if (i - 1 >= 0 && i - 1 <= m && j >= 0 && j <= n && grid[i-1][j] == '1' && !visited[i-1][j]) {
            bfs(grid, visited, m, n, i-1, j);
        }
        if (i >= 0 && i <= m && j - 1 >= 0 && j - 1 <= n && grid[i][j-1] == '1' && !visited[i][j-1]) {
            bfs(grid, visited, m, n, i, j-1);
        }
        if (i + 1 >= 0 && i + 1 <= m && j >= 0 && j <= n && grid[i+1][j] == '1' && !visited[i+1][j]) {
            bfs(grid, visited, m, n, i+1, j);
        }
        if (i >= 0 && i <= m && j + 1 >= 0 && j + 1 <= n && grid[i][j+1] == '1' && !visited[i][j+1]) {
            bfs(grid, visited, m, n, i, j+1);
        }
    }
};

int main() {
    Solution s;
   vector<vector<char>> grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    // vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    cout << s.numIslands(grid);
}