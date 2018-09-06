#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
//DP
    int uniquePaths(int m, int n) {
        //n*m
        // int** a = new int* [n];
        // for (int i = 0; i < n; ++i) {
        //     a[i] = new int[m];
        // }
        vector<vector<int>> a(n, vector<int>(m));
        for (int j = 0; j < m; ++j) {
            a[0][j] = 1;
        }
        for (int i = 0; i < n; ++i) {
            a[i][0] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }
        return a[n-1][m-1];
    }
};
int main() {
    Solution s;
    cout << s.uniquePaths(3,2);
}