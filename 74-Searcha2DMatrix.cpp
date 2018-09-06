#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int row = -1;
        int m = matrix.size();
        int n = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        for (int i = 0; i < matrix.size(); ++i) {
            if (target == matrix[i][0]) return true;
            else if (target < matrix[i][0]) {
                row = i-1;
                break;
            }
        }
        if (row == -1) {
            for (int j = 0; j < n; ++j) {
                if (target == matrix[m-1][j]) return true;
            }
            return false;
        }
        else {
            for (int j = 0; j < n; ++j) {
                if (matrix[row][j] == target) return true;
            }
            return false;
        }
    }
};
int main() {
    Solution s;
   vector<vector<int> > matrix = {{1,3}};//{{1,3,5,7},{9,10,11,12},{13,15,17,19}};
    cout << s.searchMatrix(matrix, 1) << s.searchMatrix(matrix,3);
    // cout << matrix.size() << matrix[0].size();
}