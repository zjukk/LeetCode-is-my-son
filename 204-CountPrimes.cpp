#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
//Time Limited Excessed
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int res = 1;
        for (int i = 3; i < n; ++i) {
            if (isPrime(i)) {++res;}
        }
        return res;
    }
    bool isPrime(int num) {
        if (num <= 1) return false;
        // Loop's ending condition is i * i <= num instead of i <= sqrt(num)
        // to avoid repeatedly calling an expensive function sqrt().
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
    }
   return true;
}
};
//recursion
class Solution2 {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        return isPrime(n-1) ? countPrimes(n-1)+1 : countPrimes(n-1);
    }
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }
};
//optimize
class Solution3 {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> visited(n,false);
        for (int i = 2; i * i <= n; ++i) {
            if (!visited[i]) {
                // if (!isPrime(i)) visited[i] = true;//不再需要，因为素数必定为false,而合数一定会在下面的循环被置位true
                for (int j = i * i; j < n; j += i) {
                    visited[j] = true;
                }
            } 
        }
        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (!visited[i]) ++res;
        }
        return res;
    }
    // bool isPrime(int n) {
    //     if (n <= 1) return false;
    //     for (int i = 2; i * i <= n; ++i) {
    //         if (n % i == 0) return false;
    //     }
    //     return true;
    // }
};
// this version runs fastest why???
class Solution4 {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> visited(n,false);
        int res = 0;
        for (int i = 2; i * i <= n; ++i) {
            if (!visited[i]) {
                for (int j = 2; i * j < n; ++j) {
                    visited[i*j] = true;
                }
            } 
        }
        for (int i = 2; i < n; ++i) {
            if (!visited[i]) ++res;
        }
        return res;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> num(n - 1, true);
        num[0] = false;
        int res = 0;
        for (int i = 2; i * i <= n; ++i) {
            if (num[i - 1]) {
                for (int j = i * i; j < n; j += i) {
                    num[j - 1] = false;
                }
            }
        }
        for (int j = 0; j < n - 1; ++j) {
            if (num[j]) ++res;
        }
        return res;
    }
};

int main() {
    Solution3 s;
    cout << s.countPrimes(10);
    // cout << s.isPrime(2);
    // cout << sqrt(2);
    // cout << s.isPrime(4);
    // cout <<pow(4,1/2);
}