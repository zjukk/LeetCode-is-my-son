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
        int mn = INT_MAX;
        int profit = 0;
        for (int i = 0; i < n; ++i) {
            mn = min(mn, prices[i]);
            profit = max(profit, prices[i] - mn);
        }   
        return profit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> v;
        v.push_back(0);
        for (int i = 0; i < n-1; ++i) {
            v.push_back(prices[i+1] - prices[i]);
        }
        int profit = 0;
        int sum = 0;
        int L = 0, R = 0;
        while (R < n) {
            while (sum >= 0 && R < n) {
                sum += v[R++];
                profit = max(profit, sum);
            }
            ++L;
            R = L;
            sum = 0;
        }
        return profit;
    }
};
int main() {
    Solution2 s;
    vector<int> v = {7,1,5,3,6,4};
    cout << s.maxProfit(v);
}