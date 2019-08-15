#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n2+1, vector<int>(n1+1));
        for (int j = 0; j < n1+1; ++j) dp[0][j] = j;
        for (int i = 0; i < n2+1; ++i) dp[i][0] = i;
        for (int i = 1; i < n2+1; ++i) {
            for (int j = 1; j < n1+1; ++j)
                dp[i][j] = word1[j-1] == word2[i-1] ? dp[i-1][j-1] : min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]) + 1;
        }
        return dp[n2][n1];
    }
};
// if s[j] = t[i]
// dp[i][j] = dp[i-1][j-1]   #match s[j],t[i]
// else
// dp[i][j] = 1 + min(dp[i-1][j-1],  #增加一个元素s[j]
//                    dp[i-1][j],    #删除t[i]
//                    dp[i][j-1],    #替换t[i]->s[j]
//                    )

//       ∅ h o r s e
//     ∅ 0 1 2 3 4 5
//     r 1 1 2 2 3 4
//     o 2 2 1 2 3 4
//     s 3 3 2 2 3 3