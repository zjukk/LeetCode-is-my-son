#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> visited;
        //遍历行
        for (int i = 0; i < 9; i++)  {
            visited = {0,0,0,0,0,0,0,0,0};
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    visited[board[i][j]-'1']++;
                    if(visited[board[i][j]-'1'] > 1)
                    return false;
                } 
             }
        }
        //遍历列
        for (int i = 0; i < 9; i++)  {
            visited = {0,0,0,0,0,0,0,0,0};
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    visited[board[j][i]-'1']++;
                    if(visited[board[j][i]-'1'] > 1)
                    return false;
                } 
             }
        }
        //遍历小块
        for (int a = 0; a <= 6; a += 3) { 
            for (int b = 0; b <= 6; b += 3) {
                visited = {0,0,0,0,0,0,0,0,0};
                for (int i = a; i < a + 3; i++)  {
                    for (int j = b; j < b + 3; j++) {
                        if (board[i][j] != '.') {
                            visited[board[i][j]-'1']++;
                            if(visited[board[i][j]-'1'] > 1)
                            return false;
                        } 
                    }
                }
            }
        }
        return true;
    }
};
class Solution2 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return false;
        vector<vector<bool> > rowFlag(9, vector<bool>(9, false));
        vector<vector<bool> > colFlag(9, vector<bool>(9, false));
        vector<vector<bool> > cellFlag(9, vector<bool>(9, false));
        int c;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    c = board[i][j] - '1';
                    if (rowFlag[i][c] || colFlag[j][c] || cellFlag[3*(i/3) + j/3][c]) return false;
                    rowFlag[i][c] = true;
                    colFlag[j][c] = true;
                    cellFlag[3*(i/3) + j/3][c] = true;
                }
            }
        }
        return true;
    }
};
