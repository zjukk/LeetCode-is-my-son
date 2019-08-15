#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0) return res;
        res.push_back({1});
        for (int i = 1; i < numRows; ++i) {
            vector<int> cur;
            cur.push_back(1);
            for (int j = 0; j < i-1; ++j) {
                cur.push_back(res[i-1][j] + res[i-1][j+1]);
            }
            cur.push_back(1);
            res.push_back(cur);
        }
        return res;
    }
};
class Solution2 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows, vector<int>(1));
        if (numRows == 0) return res;
        for (int i = 0; i < numRows; ++i) {
            res[i][0] = 1;
            if (i == 0) continue;
            for (int j = 1; j < i; ++j) {
                res[i].push_back(res[i-1][j] + res[i-1][j-1]);
            }
            res[i].push_back(1);
        }
        return res;
    }
};
int main() {
    Solution2 s;
    vector<vector<int>> res = s.generate(5);
     cout << res.size() << endl;
    for (auto v : res) {
        for (int i : v) 
            cout << i << ",";
        cout << endl;
    }
        
}