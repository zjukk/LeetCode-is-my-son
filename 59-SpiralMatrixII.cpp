#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n==0) return {};
        vector<vector<int>> a(n, vector<int>(n,0));
        int L = 0; int R = n-1;
        int cnt = 0;
        while (L <= R) {
            if (L == R) a[L][R] = ++cnt;
            for (int i = L; i < R; ++i) {
                a[L][i] = ++cnt;
            }
            for (int i = L; i < R; ++i) {
                a[i][R] = ++cnt;
            }
            for (int i = R; i > L; --i) {
                a[R][i] = ++cnt;
            }
            for (int i = R; i > L; --i) {
                a[i][L] = ++cnt;
            }
            ++L;
            --R;
        }
        return a;
    }
};
int main() {
    Solution s;
    vector<vector<int>> v;
    v = s.generateMatrix(5);
    for (auto a : v) {
        for (auto i : a) 
        cout << i << " "; 
        cout << endl;
    }
}