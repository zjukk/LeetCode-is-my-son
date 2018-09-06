#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class solution {
public:   
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;
        string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        dfs(digits, dict, 0, "", ans);
        return ans;
    }
    void dfs(const string& digits, const string dict[], int level, string cur, vector<string>& ans) {
        if (level == digits.size()) {
            ans.push_back(cur);
            return;
        }
        string str = dict[digits[level] - '2'];
        for (int i = 0; i < str.size(); i++) {
            cur.push_back(str[i]);
            dfs(digits, dict, level + 1, cur, ans);
            cur.pop_back();
        }
    }
};
//sol2:BFS
vector<string> letterCombinations2(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        //遍历digit
        for (int i = 0; i < digits.size(); ++i) {
            int n = res.size();
            string str = dict[digits[i] - '2'];
            //遍历res
            for (int j = 0; j < n; ++j) {
                string tmp = res.front();
                res.erase(res.begin());
                //遍历str
                for (int k = 0; k < str.size(); ++k) {
                    res.push_back(tmp + str[k]);
                }
            }
        }
        return res;
    }
    //BFS:
vector<string> letterCombinations3(string digits) {
    if (digits.empty()) return {};
    string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans{""};
    for (char digit : digits){
        vector<string> tmp;
        for (string &s : ans)
            for(char c : dict[digit - '2']) {
                tmp.push_back(s + c);
            }
        ans.swap(tmp);
    }
    return ans;
}
int main() {
    //solution a;
    // vector<string> v = a.letterCombinations("23");
    vector<string> v = letterCombinations3("23");
    vector<string> a = {""};
    cout << a.size();
    for (auto &s : v) 
    {cout << s;}
}
