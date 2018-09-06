#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// 2个规律：一是只要遇到字符串的子序列或配准问题首先考虑动态规划DP，二是只要遇到需要求出所有可能情况首先考虑用递归。
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 24) return {};
        restore(s, "", res, 4);
        return res;
    }
    void restore(string s, string cur, vector<string>& res, int k) {
        if (k == 0) {
            if (s.empty()) res.push_back(cur);
        }
        for (int i = 1; i <= 3; ++i) {
            if (s.size() >= i && isValid(s.substr(0,i))) {
                if (k == 1) restore(s.substr(i), cur + s.substr(0,i), res, k-1);
                else restore(s.substr(i), cur + s.substr(0,i)+".", res, k-1);
            }
        }
    }
    bool isValid(string s) {
        int a = atoi(s.c_str());
        if (s.size() > 3 || s.empty() || (s.size() > 1 && s[0] == '0') || a > 255) return false;
        return true;
    }
};
int main() {
    Solution s;
    vector<string> res = s.restoreIpAddresses("25525511135");
    for (auto s : res) cout << s << endl;
}