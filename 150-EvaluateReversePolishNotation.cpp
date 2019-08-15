#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
//后缀表达式的计算
//Sol1 use stack
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                    int num1 = s.top();
                    s.pop();
                    int num2 = s.top();
                    s.pop();
                    if (tokens[i] == "+") s.push(num2 + num1);//将运算结果丢回栈中
                    if (tokens[i] == "-") s.push(num2 - num1);
                    if (tokens[i] == "*") s.push(num2 * num1);
                    if (tokens[i] == "/") s.push(num2 / num1);
            } else {
                s.push(atoi(tokens[i].c_str()));
            }
        }
        return s.top();
    }
};
//recursion
class Solution2 {
public:
    int evalRPN(vector<string>& tokens) {
        int op = tokens.size() - 1;
        int a = helper(tokens,op);
        cout << op;
        return a;
    }
    //注意op的类型为int&
    int helper(vector<string>& tokens, int& op) {
        string s = tokens[op];
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            int v1 = helper(tokens, --op);
            int v2 = helper(tokens, --op);
            if (s == "+") return v2 + v1;
            else if (s == "-") return v2 - v1;
            else if (s == "*") return v2 * v1;
            else return v2 / v1;
        } else {
            // return atoi(s.c_str());
            return stoi(s);
        }
    }
};
int main() {
    Solution2 s;
    vector<string> tokens = {"-78","-33","196","+","-19","-","115","+","-","-99","/",
    "-18","8","*","-86","-","-","16","/","26","-14","-","-","47","-","101","-","163",
    "*","143","-","0","-","171","+","120","*","-60","+","156","/","173","/","-24","11",
    "+","21","/","*","44","*","180","70","-40","-","*","86","132","-84","+","*","-",
    "38","/","/","21","28","/","+","83","/","-31","156","-","+","28","/","95","-",
    "120","+","8","*","90","-","-94","*","-73","/","-62","/","93","*","196","-","-59",
    "+","187","-","143","/","-79","-89","+","-"};
    cout << s.evalRPN(tokens);
}