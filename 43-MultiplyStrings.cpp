#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        vector<int> v(n1+n2);//最多n1+n2位，用于存放临时结果。
        int k = n1 + n2 -2;//important 
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                v[k - (i + j)] += (num1[i] - '0') * (num2[j] - '0'); //用于存放所有i+j位乘法结果的乘积。
            }
        }
        int carry = 0;
        for (int i = 0; i < n1 + n2; ++i) {
            v[i] += carry;
            carry = v[i] / 10;
            v[i] %= 10; 
        }
        int i = k+1;
        while (v[i] == 0) --i;
        if (i < 0) return "0";
        string res;
        for (int j = i; j >= 0; --j) {
            res.push_back('0' + v[j]);
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.multiply("289","758");
}