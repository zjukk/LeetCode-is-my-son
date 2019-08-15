#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>

using namespace std;
// 我们其实可以求至少k次交易的最大利润，找到通解后可以设定 k = 2，即为本题的解答。

// 我们定义local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润，此为局部最优。

// 然后我们定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润，此为全局最优。它们的递推式为：

// local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)

// global[i][j] = max(local[i][j], global[i - 1][j])

// 其中局部最优值是比较前一天并少交易一次的全局最优加上大于0的差值，

// 和前一天的局部最优加上差值中取较大值，而全局最优比较局部最优和前一天的全局最优。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int local[n][3] = {0}, global[n][3] = {0};
        for (int i = 1; i < n; ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j < 3; ++j) {
                local[i][j] = max(global[i-1][j-1] + max(diff, 0), local[i-1][j] + diff);
                global[i][j] = max(local[i][j], global[i-1][j]);
            }
        }
        return global[n-1][2];
    }
};
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        if (n == 2) { return prices[1] - prices[0] > 0 ? prices[1] - prices[0] : 0;};

        vector<int> profits;
        int profit = 0;
        int mn = prices[0];
        for (int i = 1; i < n; ++i) {
            mn = min(mn, prices[i]);
            if (i == n-1 || (prices[i] >= prices[i-1] && prices[i] > prices[i+1])) {
                profit = prices[i] - mn;
                profits.push_back(profit);
                mn = prices[i+1];
            }
        }
        sort(profits.rbegin(), profits.rend());
        int res = 0;
        for (int i = 0; i < profits.size(); ++i) {
            if (i == 2) break;
            res += profits[i];
        }
        return res;
    }
};
// class Solution2 {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         if (n <= 1) return 0;
//         vector<int> profits;
//         vector<int> cur;
//         dfs(profits, cur, prices, true, 0, 0, n);
//         profits.push_back(0);
//         int size = profits.size();
//         sort(profits.begin(), profits.end());
//         return profits[size-1];
//     }
//     void dfs(vector<int>& profits, vector<int>& cur, vector<int>& prices, bool buy, int level, int index, int n) {
//         if (level == 4 && !buy) {profits.push_back(cur[1] + cur[3] - cur[0] - cur[2]); return;}
//         if (level == 3 || level == 2) {profits.push_back(cur[1] - cur[0]);}
//         if (index >= n-1) return;
//         for (int i = index; i < n; ++i) {
//             if (buy) {
//                 //i+1 < n
//                 if (i + 1 < n && prices[i+1] > prices[i]) {
//                     cur.push_back(prices[i]);
//                     dfs(profits, cur, prices, !buy, level + 1, index + 1, n);
//                     cur.pop_back();
//                 }
//             } else {
//                 if (i == n-1 || (i + 1 < n && prices[i] >= prices[i-1] && prices[i] > prices[i+1])) {
//                     cur.push_back(prices[i]);
//                     dfs(profits, cur, prices, !buy, level + 1, index + 1, n);
//                     cur.pop_back();
//                 }
//             }
//         }
//     }
// };
int main() {
    Solution s;
    vector<int> v = {1,2,4,2,5,7,2,4,9,0};
    cout << s.maxProfit(v);
}
