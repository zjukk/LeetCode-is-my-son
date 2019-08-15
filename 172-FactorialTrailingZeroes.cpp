#include <iostream>
#include <cmath>
using namespace std;
//当n很大的时候，n!会溢出
class Solution {
public:
    int trailingZeroes(int n) {
        long long num = jc(n);
        int i = 1;
        for (;;++i) {
            if (num % (long long)pow(10,i) != 0) return i-1;
        }
    }
    long long jc(int n) {
        if (n <= 1) return 1;
        return n*jc(n-1);
    }
};
//求一个数的阶乘末尾0的个数，也就是要找乘数中10的个数，而10可分解为2和5，
// 而我们可知2的数量又远大于5的数量，那么此题即便为找出5的个数。
// 仍需注意的一点就是，像25,50(5*5*2),125，这样的不只含有一个5的数字需要考虑进去。

class Solution2 {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            res += n/5;//计算有多少个能被5整除的数
            n /= 5;
        }
        return res;
    }
};
int main() {
    Solution2 s;
    // cout << s.jc(13) << endl;
    cout << s.trailingZeroes(125);
}