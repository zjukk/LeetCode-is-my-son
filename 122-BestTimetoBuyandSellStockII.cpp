#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>
using namespace std;
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (prices[i + 1] > prices[i]) {
                profit += prices[i + 1] - prices[i];
            }
        }
        return profit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || n == 1) return 0;
        if (n == 2) {
            return prices[0] > prices[1] ? 0 : prices[1] - prices[0];
        }
        int mn = prices[0];
        int profit = 0;
        for (int i = 1; i < n; ++i) {
            mn = min(mn, prices[i]);
            if (i == n-1 || prices[i] >= prices[i-1] && prices[i] > prices[i+1]) {
                profit += prices[i] - mn;
                mn = prices[i+1];
                i++;
            }
        }
        return profit;
    }
};
int main() {
    Solution2 s;
    vector<int> v{7,1,5,3,6,4};
    cout << s.maxProfit(v);
}