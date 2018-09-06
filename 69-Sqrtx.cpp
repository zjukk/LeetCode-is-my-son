#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int L = 0;
        int R = x;
        while (L < R) {
            int mid = (L+R)/2;
            if (x/mid == mid) return mid;
            if (x / mid < mid) {//mid*mid > x, mid*mid会溢出！！！！
                R = mid;//因为是求最后一个比x小的数
            }
            else {
                L = mid + 1;
            } 
        }
        return R-1;
    }
};
class Solution2 {
public:
    // int mySqrt(int x) {
    //     if (x <= 1) return x;
    //     int left = 0, right = x/2 + 1;//对于一个非负数n，它的平方根不会小于大于（n/2+1）
    //     while (left < right) {
    //         int mid = left + (right - left) / 2;
    //         if (x / mid >= mid) left = mid + 1;
    //         else right = mid;
    //     }
    //     return right - 1;
    // }
    int mySqrt(int x) {
    long long i = 0;
    long long j = x / 2 + 1;
    while (i <= j)
    {
        long long mid = (i + j) / 2;
        long long sq = mid * mid;
        if (sq == x) return mid;
        else if (sq < x) i = mid + 1;
        else j = mid - 1;
    }
    return j;
}
};
//牛顿迭代法 xi+1= xi - (xi2 - n) / (2xi) = xi - xi / 2 + n / (2xi) = xi / 2 + n / 2xi = (xi + n/xi) / 2
class Solution3 {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        double res = x/2 + 1;//or res = 1;
        double last = 0;
        while (abs(res-last) > 1e-6) {
            last = res;
            res = (res + x / res) / 2;
        }
        return int(res);
    }
};
int main() {
    Solution3 s;
    cout << s.mySqrt(2);
}