#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int up = 0, down = matrix.size() - 1;
        while(up <= down) {
            help(matrix, up, down);
            ++up;
            --down;
        }
    }
    void help(vector<vector<int>>& matrix, int up, int down) {
        int n = matrix.size();
        if (up == down) return;
        int i;
        //逆时针交换，右和上交换
        for (i = 0; i < down - up; ++i) { //i < down - up 太细节了！！！
            int tmp = matrix[up][up+i];
            matrix[up][up+i] = matrix[up+i][down];
            matrix[up+i][down] = tmp;
        }
        for (i = 0; i < down - up; ++i) {
            int tmp = matrix[up][up+i];
            matrix[up][up+i] = matrix[down-i][up];
            matrix[down-i][up] = tmp;
        }
        for (i = 0; i < down - up; ++i) {
            int tmp = matrix[down-i][up];
            matrix[down-i][up] = matrix[down][down-i];
            matrix[down][down-i] = tmp;
        }
    }
};

int main() {
    Solution s;
    // vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    // vector<vector<int>> matrix = {{2,29,20,26,16,28},{12,27,9,25,13,21},{32,33,32,2,28,14},{13,14,32,27,22,26},{33,1,20,7,21,7},{4,24,1,6,32,34}};
    for (auto& v : matrix) {
        for (auto i : v)
        cout << i << " ";
    cout << endl;
    }
    //s.rotate(matrix);
    s.help(matrix, 0, 3);
    for (auto& v : matrix) {
        for (auto i : v)
        cout << i << " ";
    cout << endl;
    }
    cout << endl;
    s.help(matrix, 1, 2);
    //s.help(matrix, 2, 3);
    for (auto& v : matrix) {
        for (auto i : v)
        cout << i << " ";
    cout << endl;
    }
}