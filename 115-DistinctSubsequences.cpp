#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 看到有关字符串的子序列或者配准类的问题，首先应该考虑的就是用动态规划Dynamic Programming来求解，
// 这个应成为条件反射。而所有DP问题的核心就是找出递推公式
// 当更新到dp[i][j]时，dp[i][j] >= dp[i][j - 1] 总是成立，再进一步观察发现，
// 当 T[i - 1] == S[j - 1] 时，dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1]，
// 若不等， dp[i][j] = dp[i][j - 1]

// if t[i] == s[j]
// dp[i][j] = dp[i-1][j]  #skip s[j] 跳过s最后一个字符的匹配
//         + dp[i-1][j-1] #match s[j], t[i]
// else
// dp[i][j] = dp[i-1][j]  #skip s[j] 必须跳过s最后一个字符的匹配

class Solution2 {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>> dp(n2+1, vector<int>(n1+1));
        for (int j = 0; j < n1+1; ++j) dp[0][j] = 1;
        for (int i = 1; i < n2+1; ++i) dp[i][0] = 0;
        for (int i = 1; i < n2 + 1; ++i) {
            for (int j = 1; j < n1 + 1; ++j) 
                dp[i][j] = t[i-1] == s[j-1] ? dp[i-1][j-1] + dp[i][j-1] : dp[i][j-1];//t[i-1] == s[j-1] 而非 t[i] == s[j] 
        }
        return dp[n2][n1];
    }
};
class Solution3 {
public:
    int numDistinct(string S, string T) {
        int dp[T.size() + 1][S.size() + 1];
        for (int i = 0; i <= S.size(); ++i) dp[0][i] = 1;    
        for (int i = 1; i <= T.size(); ++i) dp[i][0] = 0;    
        for (int i = 1; i <= T.size(); ++i) {
            for (int j = 1; j <= S.size(); ++j) {
                dp[i][j] = dp[i][j - 1] + (T[i - 1] == S[j - 1] ? dp[i - 1][j - 1] : 0);
            }
        }
        return dp[T.size()][S.size()];
    }
};

//Time Limit Exceeded dfs
class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        int cnt = 0;
        dfs(s, t, "", cnt, 0, 0, n1, n2);
        return cnt;
    }
    void dfs(string s, string t, string cur, int& cnt, int index, int level, int n1, int n2) {
        if (cur == t)  {
            ++cnt;
            return;
        }
        for (int i = index; i < n1; ++i) {
            if (s[i] == t[level]) {
                cur.push_back(s[i]);
                dfs(s, t, cur, cnt, i+1, level+1, n1, n2);
                cur.pop_back();
            }
        }
    }
};
int main() {
    Solution s;
    string S = "daacaedaceacabbaabdccdaaeaebacddadcaeaacadbceaecddecdeedcebcdacdaebccdeebcbdeaccabcecbeeaadbccbaeccbbdaeadecabbbedceaddcdeabbcdaeadcddedddcececbeeabcbecaeadddeddccbdbcdcbceabcacddbbcedebbcaccac", T = "ceadbaa";
    // string S = "", T = "a";
    cout << s.numDistinct(S, T);
}


// 试辨析下列情况的异同
// for(int i = 0;....) {
//     dfs(level+1)
// }
// for(int i = 0;....) {
//     dfs(i+1)
// }
// for(int i = level;....) {
//     dfs(i)
// }
// for(int i = level;....) {
//     dfs(i+1)
// }
// for(int i = level;....) {
//     dfs(level+1)
// }