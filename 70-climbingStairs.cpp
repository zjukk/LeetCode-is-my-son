#include <iostream>
#include <vector>

using namespace std;
    int climbStairs(int n) {
        if (n == 0)
        return 0;
        // if (n == 1)
        // return 1;
        // if (n == 2)
        // return 2;
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        for (int i = 2; i < n; i++) {
            v.push_back(v[i-1] + v[i-2]);
        }
        return v[n-1];
        //return climbStairs(n-1) + climbStairs(n-2);
    }

    int main() {
    cout << climbStairs(4);
    }