#include <iostream>
#include <stack>

using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= s2.top()) s2.push(x);
    }
    
    void pop() {
        if (s2.top() == s1.top()) s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
    stack<int> s1, s2;
};
//using 1 stack
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min_val = INT_MAX;
    }
    
    void push(int x) {
        if (x <= min_val) { //注意是《= 而不能是 <，因为在pop()的时候，相同的数值会被pop两次
            s.push(min_val); //记录之前的最小值
            min_val = x;
        }
        s.push(x);
    }
    
    void pop() {
        int t = s.top();
        s.pop();
        if (t == min_val) {
            min_val = s.top();
            s.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_val;
    }
    stack<int> s;
    int min_val;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */