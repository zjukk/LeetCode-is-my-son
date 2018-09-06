#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <math.h>
#include <limits>
using namespace std;

int reverse(int x) {
        int y = x;
        if (y == 0 || y > pow(2, 31) - 1 || y < -pow(2, 31))
            return 0;
        stack<int> s;   
        y = y < 0 ? -y : y;
        while (y != 0) {
            s.push(y % 10);
            y /= 10;
        }
        int ans = 0;
        int i = 0;
        while (!s.empty()) {
            ans += s.top() * pow(10, i++);
            s.pop();
        }
        if (ans == INT_MIN) return 0; //not precise
        return x > 0 ? ans : -ans;
    }
    int reverse2(int x) {
        int pop = 0;
        int rev = 0;
        while (x != 0) {
            pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8)) return 0;    
            rev = rev*10 + pop;
        }
        return rev;
    }
    int main() {
        //cout << (2147483648 > 1534236469);
        //cout << INT_MAX << endl << INT_MIN;
        cout << reverse2(1534236469);
    }