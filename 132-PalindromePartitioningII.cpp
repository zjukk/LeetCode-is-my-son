#include <iostream>
#include <vector>
#include <string>
using namespace std;
//Time Limit Exceeded
// class Solution {
// public:
//     int minCut(string s) {
//         if (isPalindrome(s, 0, s.size()-1)) return 0;
//         vector<string> res;
//         vector<string> cur;
//         DFS(res, cur, s, 0, 0);
//         return res.size() - 1;
//     }
//     void DFS(vector<string>& res, vector<string>& cur, string& s, int start, int cnt) {
//         if (start == s.size() && (cnt < res.size() - 1 || res.empty())) {
//             res = cur;
//             return;
//         }
//         for (int i = start; i < s.size(); ++i) {
//             if (isPalindrome(s, start, i) && cnt < res.size-1) {
//                 cur.push_back(s.substr(start, i-start+1));
//                 ++cnt;
//                 DFS(res, cur, s, i+1, cnt);
//                 --cnt;
//                 cur.pop_back();
//             }
//         }
//     }
//     bool isPalindrome(string& s, int begin, int end) {
//         while (begin <= end) {
//             if (s[begin] != s[end])
//                 return false;
//             ++begin;
//             --end;
//         }
//         return true;
//     }
// };
//双重dp，在用dp求解判断回文字符串的同时，利用dp求解最小的cut，cut[i]记录从i到字符串末尾的minCut,
// 第二层循环j从i开始遍历到字符串末尾，当s(i,j)构成回文时，才更新cut[i]，cut[i] = 

class Solution2 {
public:
    int minCut(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        //cut[i]代表从i到最后的最小分割数，前提是i到j是回文字符串
        vector<int> cut(s.size() + 1, -1);
        for (int i = s.size() - 1; i >= 0; --i) {
            cut[i] = INT_MAX;
            for (int j = i; j < s.size(); ++j) {
                if ((s[i] == s[j]) && (j - i < 2 || dp[i+1][j-1])) {
                    dp[i][j] = 1;
                    cut[i] = min(cut[i], cut[j+1] + 1);
                }
            }
        }
        return cut[0];
    }
};
int main() {
    Solution2 s;
    string str = "apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp";
    // string str = "aab";
    cout << s.minCut(str);
    // vector<string> res = s.minCut(str);
    // for (auto s : res) {
    //     cout << s << " ";
    // }
    // cout << res.size();
}