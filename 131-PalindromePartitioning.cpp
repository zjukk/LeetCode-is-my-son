#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Time Limit Excessed
class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) return {};
        vector<vector<string>> res;
        vector<string> cur;
        dfs(res, cur, s, 0);
        return res;
    }
    void dfs(vector<vector<string>>& res, vector<string>& cur, string s, int level) {
        if (returnSize(cur) == s.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = level; i < s.size(); ++i) {
            for (int j = 1; j <= s.size() - i; ++j) {
                string sub = s.substr(i, j);
                if (isPalindrome(sub)) {
                    cur.push_back(sub);
                    dfs(res, cur, s, i+j);//不再是进入i+1,而应该是i+j
                    cur.pop_back();
                }
            }
        }
    }
    int returnSize(vector<string>& v) {
        int sum = 0;
        for (string s : v) {
            sum += s.size();
        }
        return sum;
    }
    bool isPalindrome(string s) {
        if (s.size() <= 1) return true;
        int l = 0;
        int r = s.size() - 1;
        while (l <= r) {
            if (s[l] != s[r]) return false;
            ++l;
            --r;
        }
        return true;
    }
};
class Solution2 {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        partitionDFS(res, cur, s, 0);
        return res;
    }
    void partitionDFS(vector<vector<string>>& res, vector<string>& cur, string& s, int start) {
        if (start == s.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                cur.push_back(s.substr(start, i-start+1));
                partitionDFS(res, cur, s, i+1);
                cur.pop_back();
            }
        }
    }
    bool isPalindrome(string& s, int begin, int end) {
        while (begin <= end) {
            if (s[begin] != s[end])
                return false;
            ++begin;
            --end;
        }
        return true;
    }
};
int main() {
    Solution2 s;
    string str = "seeslaveidemonstrateyetartsnomedievalsees";
    // string str = "aab";
    vector<vector<string>> res = s.partition(str);
    // for (auto v : res) {
    //     for (string s : v)
    //         cout << s << " ";
    //     cout << endl;
    // }
    cout << res.size();
}