#include <iostream>
#include <vector>
using namespace std;
//To revise
// class Solution {
// public:
//     void solve(vector<vector<char>>& board) {
//         if (board.empty()) return;
//         int m = board.size() - 1;
//         int n = board[0].size() - 1;
//         vector<vector<bool>> visited(m+1, vector<bool>(n, false));
//         vector<pair<int,int>> rec;
//         for (int i = 0; i <= m; ++i) {
//             for (int j = 0; j <= n; ++j) {
//                 if (board[i][j] == 'O' && !bfs(board, visited, rec, m, n, i, j)) {
//                     board[i][j] = 'X';
//                     for (int k = 0; k < rec.size(); ++k)
//                         board[rec[k].first][rec[k].second] = 'X';
//                 } 
//                 rec = {};
//             }
//         }
//     }
//     bool bfs(vector<vector<char>>& board, vector<vector<bool>>& visited, vector<pair<int,int>>& rec, int m, int n, int i, int j) {
        
//         if (!visited[i][j] && (i == 0 || i == m || j == 0 || j == n)) {
//             visited[i][j] = true;
//             rec.push_back({i, j});
//             return true;
//         }
//         if (i - 1 >= 0 && i - 1 <= m && j >= 0 && j <= n && board[i-1][j] == 'O' && !visited[i-1][j]) {
//             visited[i-1][j] = true;
//             rec.push_back({i-1, j});
//             return bfs(board, visited, rec, m, n, i-1, j);
//         }
//         if (i >= 0 && i <= m && j - 1 >= 0 && j - 1 <= n && board[i][j-1] == 'O' && !visited[i][j-1]) {
//             visited[i][j-1] = true;
//             rec.push_back({i, j-1});
//             return bfs(board, visited, rec, m, n, i, j-1);
//         }
//         if (i + 1 >= 0 && i + 1 <= m && j >= 0 && j <= n && board[i+1][j] == 'O' && !visited[i+1][j]) {
//             visited[i+1][j] = true;
//             rec.push_back({i+1, j});
//             return bfs(board, visited, rec, m, n, i+1, j);
//         }
//         if (i >= 0 && i <= m && j + 1 >= 0 && j + 1 <= n && board[i][j+1] == 'O' && !visited[i][j+1]) {
//             visited[i][j+1] = true;
//             rec.push_back({i, j+1});
//             return bfs(board, visited, rec, m, n, i, j+1);
//         }
//         return false;
//     }
// };
//bfs
// 扫面矩阵的四条边，如果有O，则用DFS遍历，将所有连着的O都变成另一个字符，
// 比如，这样剩下的O都是被包围的，然后将这些O变成X，把变回O就行了。
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size() - 1;
        int n = board[0].size() - 1;
        vector<vector<bool>> visited(m+1, vector<bool>(n, false));
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if ((i == 0 || i == m || j == 0 || j == n) && board[i][j] == 'O')
                    process(board, visited, m, n, i, j);
            }
        }
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
    void process(vector<vector<char>>& board, vector<vector<bool>>& visited, int m, int n, int i, int j) {
        board[i][j] = 'A';
        visited[i][j] = true;
        if (i - 1 >= 0 && i - 1 <= m && j >= 0 && j <= n && board[i-1][j] == 'O' && !visited[i-1][j]) {
            process(board, visited, m, n, i-1, j);
        }
        if (i >= 0 && i <= m && j - 1 >= 0 && j - 1 <= n && board[i][j-1] == 'O' && !visited[i][j-1]) {
            process(board, visited, m, n, i, j-1);
        }
        if (i + 1 >= 0 && i + 1 <= m && j >= 0 && j <= n && board[i+1][j] == 'O' && !visited[i+1][j]) {
            process(board, visited, m, n, i+1, j);
        }
        if (i >= 0 && i <= m && j + 1 >= 0 && j + 1 <= n && board[i][j+1] == 'O' && !visited[i][j+1]) {
            process(board, visited, m, n, i, j+1);
        }
    }
};
int main() {
    Solution s;
    vector<vector<char>> board = {{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
    // vector<vector<char>> board = {{'O','O','O','X','O'},{'X','X','X','X','X'},{'X','O','O','X','X'},{'X','X','X','X','O'}};
    s.solve(board);
    for (auto v : board) {
        for (char c : v) 
            cout << c << " ";
        cout << endl;
    }
}