    #include <iostream>
    #include <string>
    #include <algorithm>
    #include <vector>
    #include <set>

    using namespace std;
    void process(vector<string> &ans, string cur, int max, int open, int close) {
        if (close == max) {
            ans.push_back(cur);
            return;
        }
        if (open < max) {
            process(ans, cur + "(", max, open + 1, close);
        }
        if (close < open) {
            process(ans, cur + ")", max, open, close + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        process(res,"",n,0,0);
        return res;
    }

    vector<string> generateParenthesis2(int n) {
        vector<string> ans;
        if (n == 0) {
            ans.push_back("");
        }
        for (int c = 0; c < n; c++) {
            for (string& left : generateParenthesis2(c)) {
                for (string& right : generateParenthesis2(n-c-1)) {
                    ans.push_back("(" + left + ")" + right);//To enumerate something, generally we would like to express it as a sum of disjoint subsets that are easier to count.
                }
            }
        }
        return ans;
    } 
    //sol3:每个左括号后加一对括号，最前面加一对括号
    vector<string> generateParenthesis3(int n) {
        set<string> t;
        if (n == 0) t.insert("");//no repeat
        else {
            vector<string> pre = generateParenthesis(n - 1);
            for (auto a : pre) {
                for (int i = 0; i < a.size(); ++i) {
                    if (a[i] == '(') {
                        a.insert(a.begin() + i + 1, '(');
                        a.insert(a.begin() + i + 2, ')');
                        t.insert(a);
                        a.erase(a.begin() + i + 1, a.begin() + i + 3);//erase(begin,end)尾后迭代器不删除
                    }
                }
                t.insert("()" + a);
            }
        }
        return vector<string>(t.begin(), t.end());
    }



    int main() {
        vector<string> v = generateParenthesis3(3);
        for (auto &a : v){
            cout << a << endl;
        }
    }