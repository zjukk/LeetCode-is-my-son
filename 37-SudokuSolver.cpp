#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
// 本题找到解的处理是return true，因此返回值为bool
// N-Queen找到解的处理是保存解，因此返回值为void
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.empty() || board.size() != 9 || board[0].size() != 9) return;
        dfs(board, 0, 0);
    }
// 只有正确达到最终位置（即成功填充）的填充结果才可以返回，若不然，将会得到错误的填充。
// 因此辅助函数solve需要设为bool而不是void 
// 因为要判断递归的方案正确与否，所以这里的递归一定是有返回值的（除非是combination那种没有正确错误概念的backtracking）
    bool dfs(vector<vector<char>>& board, int row, int col) {
        if (row == 9) return true;//完全正确填充
        if (col == 9) return dfs(board, row + 1, 0);
        if (board[row][col] == '.') {
            for (int i = 1; i <= 9; ++i) {
                board[row][col] = i + '0';
                if (isValid(board, row, col) && dfs(board, row, col + 1)) {
                    return true;
                }
                board[row][col] = '.';
            }
        } else {
            return dfs(board, row, col + 1);
        }
        return false;
    }
    void dfs(vector<vector<char>>& board, int row, int col) {
        if (row == 9) return;
        if (col == 9) dfs(board, row + 1, 0);
        if (board[row][col] == '.') {
            for (int i = 1; i <= 9; ++i) {
                board[row][col] = i + '0';
                if (isValid(board, row, col)) {
                    dfs(board, row, col + 1);
                }
                board[row][col] = '.';
            }
        } else {
            dfs(board, row, col + 1);
        }
        return;
    }
    bool isValid(vector<vector<char> >& board, int row, int col) {
        for (int i = 0; i < 9; ++i) {
            if (i != row && board[i][col] == board[row][col]) return false;
        }
        for (int j = 0; j < 9; ++j) {
            if (j != col && board[row][j] == board[row][col]) return false;
        }
        for (int i = 3*(row/3); i < 3*(row/3) + 3; ++i) {
            for (int j = 3*(col/3); j < 3*(col/3) + 3; ++j) {
                if (i != row && j != col && board[i][j] == board[row][col]) return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.empty()) return;
        dfs(board);
    }
    bool dfs(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; ++c) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (dfs(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            if (i != row && board[i][col] == c) return false;
            if (i != col && board[row][i] == c) return false;
        }
        for (int i = 3*(row/3); i < 3*(row/3) + 3; ++i) {
            for (int j = 3*(col/3); j < 3*(col/3) + 3; ++j) {
                if (i != row && j != col && board[i][j] == c) return false;
            }
        }
        return true;
    }
};