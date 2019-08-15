#include <iostream>
#include <vector>
using namespace std;
// 最后的数是该数字范围内所有的数的左边共同的部分,我们可以从建立一个32位都是1的mask，
// 然后每次把mask向左移一位，比较m&mask和n&mask是否相同，不同再继续左移一位，直至相同，
// 然后把m和mask相与就是最终结果
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int mask = INT_MAX;
        while ((m & mask) != (n & mask)) {//位操作符一定要加括号
            mask <<= 1;
        }
        return m&mask;
    }
};
//先将m,n不断右移直到最左边的公共部分相等，记录右移的位数后再左移回来
class Solution2 {
public:
    int rangeBitwiseAnd(int m, int n) {
        int cnt = 0;
        while (m != n) {//位操作符一定要加括号
            m >>= 1;
            n >>= 1;
            ++cnt;
        }
        while (cnt--) {
            m <<= 1;
        }
        return m;
    }
};
//原理同上，利用recursive
class Solution3 {
public:
    int rangeBitwiseAnd(int m, int n) {
        return n > m ? rangeBitwiseAnd(m/2, n/2) << 1 : m;
    }
};
//如果m小于n就进行循环，n与上n-1，那么为什么要这样与呢，
// 举个简单的例子，110与上(110-1)，得到100，这不就相当于去掉最低位的1么，
// n就这样每次去掉最低位的1，如果小于等于m了，返回此时的n即可
class Solution4 {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
            n &= n-1;
        }
        return n;
    }
};