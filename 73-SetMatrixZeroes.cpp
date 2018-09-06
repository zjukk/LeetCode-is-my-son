#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        set<int> row;
        set<int> col;
        //vector<vector<bool>> isZero(m, vector<bool>(n,false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }      
        for (auto it = row.begin(); it != row.end(); ++it) {
            for (int i = 0; i < n; ++i) {
                matrix[*it][i] = 0;
            }
        }
        for (auto it = col.begin(); it != col.end(); ++it) {
            for (int i = 0; i < m; ++i) {
                matrix[i][*it] = 0;
            }
        }
        return;
    }
};
int main() {
    Solution s;
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    s.setZeroes(matrix);
    for (auto v : matrix) {
        for (auto i : v)
        cout << i;
    cout << endl;
    }
}