#include <iostream>
#include <vector>
using namespace std;
//wrong!!
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        int sum = 0;
        vector<int> res;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (int i = 0; i < positions.size(); ++i) {
            if (!inTheGroup(grid, positions[i].first, positions[i].second, grid.size() - 1, grid[0].size() - 1)) {
                ++sum;
            }
            grid[positions[i].first][positions[i].second] = 1;
            res.push_back(sum);
        }
        return res;
    }
    bool inTheGroup(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i - 1 >= 0 && i - 1 <= m && j >= 0 && j <= n && grid[i-1][j] == 1) {
            return true;
        }
        if (i >= 0 && i <= m && j - 1 >= 0 && j - 1 <= n && grid[i][j-1] == 1) {
            return true;
        }
        if (i + 1 >= 0 && i + 1 <= m && j >= 0 && j <= n && grid[i+1][j] == 1) {
            return true;
        }
        if (i >= 0 && i <= m && j + 1 >= 0 && j + 1 <= n && grid[i][j+1] == 1) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<pair<int,int>> positions = {{0,0}, {0,1}, {1,2}, {2,1}};
    vector<int> res = s.numIslands2(3, 3, positions);
    for (int i : res) cout << i;
}