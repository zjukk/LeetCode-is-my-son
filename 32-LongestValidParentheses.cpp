#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> st;
        int cnt = 0;
        int maxm = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else {
                if (st.empty()) 
                st.push(s[i]);
                else if(s[i] == ')' && st.top() == '(') {
                    st.pop();
                    cnt += 2;
                    maxm = max(maxm,cnt);
                }
            }
        }
        return cnt;
    }
};
class Solution2 {
public:
    int longestValidParentheses(string s) {
        int res = 0, start = 0;
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.empty()) {
                    start = i+1;
                } else {
                    st.pop();
                    res = st.empty() ? max(res, i - start + 1) : max(res, i - st.top());// i - st.top()而不是i - st.top() + 1,因为已经pop掉了一个元素
                }
            }
        }
        return res;
    }
};
int main() {
    Solution2 s;
    int cnt = s.longestValidParentheses("(()()(()");
    cout << cnt;
}