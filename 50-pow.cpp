#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
using namespace std;
    double Pow(double x, int n) {
        if (n == 0)
        return 1;
        double half = Pow(x, n/2);
        if ((n & 1) == 0) return half*half;
        return half*half*x;
    }
    double myPow(double x, int n) {
        if (n < 0) {
           return 1 / Pow(x, -n);
        }
        return Pow(x,n);
    }


    double myPow2(double x, int n) {
        if (n == 0) return 1;
        double half = myPow(x, n / 2);
        if (n % 2 == 0) return half * half;
        else if (n > 0) return half * half * x;
        else return half * half / x;
    }
    int main() {
       cout << myPow2(2.0,-2);

    }