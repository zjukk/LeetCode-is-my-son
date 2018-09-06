#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
//like climbing stairs 以及斐波那契数列。
// 这道题要求解码方法，跟之前那道 Climbing Stairs 爬梯子问题 非常的相似，
// 但是还有一些其他的限制条件，比如说一位数时不能为0，两位数不能大于26，
// 其十位上的数也不能为0，出去这些限制条件，根爬梯子基本没啥区别，也勉强算特殊的斐波那契数列，
// 当然需要用动态规划Dynamci Programming来解。建立一位dp数组，长度比输入数组长多多2，
// 全部初始化为1，因为斐波那契数列的前两项也为1，然后从第三个数开始更新，对应数组的第一个数。
// 对每个数组首先判断其是否为0，若是将改为dp赋0，若不是，赋上一个dp值，此时相当如加上了dp[i - 1], 
// 然后看数组前一位是否存在，如果存在且满足前一位不是0，且和当前为一起组成的两位数不大于26，
// 则当前dp值加上dp[i - 2], 至此可以看出来跟斐波那契数组的递推式一样
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            dp[i+1] += s[i] - '0' > 0 ? dp[i] : 0;
            dp[i+1] += s[i-1] && s[i-1] != '0' && (s[i-1]-'0')*10+(s[i]-'0') <= 26 ? dp[i-1] : 0;
        }
        return dp[n];
    }
};
int main() {
    Solution s;
    cout << s.numDecodings("27");
}