#include <iostream>
#include <string>
#include <stack>
using namespace std;

    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if(st.empty()) {
                st.push(s[i]);
                continue;
            }
            if (s[i] - st.top() == 1 || s[i] - st.top() == 2) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        return st.empty();
    }

    //sol2:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) return false;
                if (s[i] == ')' && st.top() != '(') return false;
                if (s[i] == '}' && st.top() != '{') return false;
                if (s[i] == ']' && st.top() != '[') return false;
                st.pop();
            }
        }
        return st.empty();
    }
    int main() {
        string s = "([)]";
        cout << isValid(s);
    }