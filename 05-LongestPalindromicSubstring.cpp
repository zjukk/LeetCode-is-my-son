#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
//sol1:
string process(string str) {
    string res;
    for(int i = 0; i < 2*str.size() + 1; i++) {
        res.push_back((i & 1) ? str[i/2]: '#') ;
    }
    return res;
}
string longestPalindrome(string s) {
    string ans;
    s = process(s);
    pair<int, int> maxl = {0,0};
    for (int i = 1; i < s.size(); i++) {
        int L = i - 1;
        int R = i + 1;
        while(s[L] == s[R] && L >= 0 && R < s.size()) {
            L--;
            R++;
        }
        if(R-L-2 > maxl.second - maxl.first) {
            maxl.first = L+1;
            maxl.second = R-1;
        }
    }
    if(maxl.second - maxl.first == 0)
        return "";
    for (int i = maxl.first + 1; i <maxl.second;){
        ans +=s[i];
        i += 2;
    }
    return ans;
}
};
// 此题还可以用动态规划Dynamic Programming来解，根Palindrome Partitioning II 拆分回文串之二的解法很类似，
// 我们维护一个二维数组dp，其中dp[i][j]表示字符串区间[i, j]是否为回文串，当i = j时，只有一个字符，肯定是回文串，
// 如果i = j + 1，说明是相邻字符，此时需要判断s[i]是否等于s[j]，如果i和j不相邻，即i - j >= 2时，
// 除了判断s[i]和s[j]相等之外，dp[j + 1][i - 1]若为真，就是回文串，通过以上分析，可以写出递推式如下：
// dp[i, j] = 1                           if i == j

//  = s[i] == s[j]                        if j = i + 1

//  = s[i] == s[j] && dp[i + 1][j - 1]    if j > i + 1      

// 这里有个有趣的现象就是如果我把下面的代码中的二维数组由int改为vector<vector<int> >后，就会超时，
// 这说明int型的二维数组访问执行速度完爆std的vector啊，所以以后尽可能的还是用最原始的数据类型吧。
//溢出
class Solution3 {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool **dp = new bool* [n];
        for (int i = 0; i < n; ++i) {
            dp[i] = new bool[n];
        }
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for (int i = n - 2; i >= 0; --i) {//由于下一层的值会受到上一层影响（dp[i][j]受到dp[i+1][j-1]影响），所以从上一层开始遍历
            for (int j = i + 1; j < n; ++j) {
                if (j == i + 1 && s[j] == s[i]) dp[i][j] = true;
                else if (j - i > 1 && dp[i+1][j-1] == true && s[i] == s[j]) dp[i][j] = true;
                else dp[i][j] = false;
            }
        }
        string res;
        res.push_back(s[0]);
        int dif = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (dp[i][j] && (j - i) > dif) {
                    dif = j - i;
                    res = s.substr(i,j-i+1);
                }
            }
        }
        return res;
    }
};

class Solution4 {
public:
    string longestPalindrome(string s) {
        int dp[s.size()][s.size()] = {0}, left = 0, right = 0, len = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
                if (dp[j][i] && len < i - j + 1) {
                    len = i - j + 1;
                    left = j;
                    right = i;
                }
            }
            dp[i][i] = 1;
        }
        return s.substr(left, right - left + 1);
    }
};

int main() {
    // Solution4 s;
    // cout << s.longestPalindrome("acdcabaee");
    string s = "abc";
    int dp[s.size()][s.size()] = {0};
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s.size(); ++j) 
            cout << dp[i][j] << " ";
        cout << endl;
    }
}