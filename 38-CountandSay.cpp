#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
        return string("1");
        string s = countAndSay(n-1) + "#";
        string ans;
        int cnt = 1;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i+1]) {
                ++cnt;
            } else {
                ans.push_back(cnt + '0');
                ans.push_back(s[i]);
                cnt = 1;
            }
        }
        return ans;
    }
};
int main() {
    Solution s;
    //cout << s.countAndSay(4) << endl << s.countAndSay(5);
    cout << s.countAndSay(5);
    // string str;
    // int i = 1;
    // str.push_back(i+'0');
    // cout<<str;
}