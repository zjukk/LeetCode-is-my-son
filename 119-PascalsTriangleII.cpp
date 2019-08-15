#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows = rowIndex + 1;
        vector<vector<int>> res;
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
        return res[rowIndex];
    }
};
//O(k),利用杨辉三角的性质
// 杨辉三角主要有下列五条性质：

// 杨辉三角以正整数构成，数字左右对称，每行由1开始逐渐变大，然后变小，回到1。
// 第n行的数字个数为n个。
// ***第n行的第k个数字为组合数C_{n-1}^{k-1},C(k-1,n-1)***
// 第n行数字和为2^{n-1}。
// 除每行最左侧与最右侧的数字以外，每个数字等于它的左上方与右上方两个数字之和
// （也就是说，第n行第k个数字等于第n-1行的第k-1个数字与第k个数字的和）。
// 这是因为有组合恒等式：C_{n}^{i}=C_{n-1}^{i-1}+C_{n-1}^{i}。可用此性质写出整个杨辉三角形。
class Solution2 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for (int i = 1; i <= rowIndex + 1; ++i) {
            res.push_back(combination(i-1, rowIndex));
        }
        return res;
    }
    // incorrect OJ overflow
    int combination(int k, int n) {
        if (k == 0) return 1;
        if (k > n - k) k = n - k;
        long long numerator = 1, denomenator = 1;
        int cnt = 0;
        while (cnt < k) {
            numerator *= n--;
            ++cnt;
        }
        while (k > 0) {
            denomenator *= k--;
        }
        cout << numerator << " " << denomenator << endl;
        return numerator/denomenator;
    }
};
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 0);//用0填充
        for (int i = 0; i <= rowIndex; ++i) {
            if (i == 0) {
                res[0] = 1;
                continue;
            }
            for (int j = rowIndex; j >= 1; --j) {
                res[j] = res[j] + res[j-1];
            }
        }
        return res;
    }
};

int main() {
    Solution2 s;
    // vector<int> res = s.getRow(13);
    //     for (int i : res) {
    //         cout << i << ",";
    // }    
    cout << s.combination(11,13);
}
