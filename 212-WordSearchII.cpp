#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//runtime error
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty()) return {};
        vector<string> res;
        int m = board.size();
        int n = board[0].size();
        for (int k = 0; k < words.size(); ++k) {
            vector<vector<bool> > visited(m, vector<bool>(n, false));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dfs(board, words[k], i, j, 0, visited)) res.push_back(words[k]);
                }
            }
        }
        return res;
    }
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int level, vector<vector<bool> >& visited) {
        if (level == word.size()) return true;
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i > m || j < 0 || j > n || board[i][j] != word[level]) return false;
        visited[i][j] = true;
        if(dfs(board, word, i-1, j, level + 1, visited) || dfs(board, word, i+1, j, level + 1, visited) || 
        dfs(board, word, i, j-1, level + 1, visited) || dfs(board, word, i, j+1, level + 1, visited)) return true;
        visited[i][j] = false;
        return false;
    }
};
int main() {
    Solution s;
    vector<vector<char>> board = {{'a'}};//{{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"ab"};//{"oath","pea","eat","rain"};
    vector<string> res = s.findWords(board, words);
    for (string& s : res) 
    cout << s << " ";
}