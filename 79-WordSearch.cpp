#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, i, j, word, 0, visited))
                return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int level, vector<vector<bool> >& visited) {
        if (level == word.size()) return true;
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[level] || visited[i][j]) 
            return false;
        visited[i][j] = true;
        if (dfs(board, i-1, j, word, level+1, visited) || dfs(board, i+1, j, word, level+1, visited) || 
        dfs(board, i, j-1, word, level+1, visited) || dfs(board, i, j+1, word, level+1, visited)) {
        return true;
        }
        visited[i][j] = false;
        return false;
    }
};
int main() {
    Solution s;
    vector<vector<char> > board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABED";
    cout << s.exist(board, word);
}