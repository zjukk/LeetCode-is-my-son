#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//brute force
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(); 
        if (n == 1) return nums[0];
        int res = nums[0];
        for (int i = 0; i < n; ++i) {
            int tmp = 1;
            for (int j = i; j < n; ++j) {
                tmp *= nums[j];
                if (tmp > res) res = tmp;
            }
        }
        return res;
    }
};
//dp*2 O(n)
class Solution2 {
public:
    pair<int,int> maxProduct(vector<int>& nums) {
        int n = nums.size(); 
        int mx = nums[0];
        int mn = nums[0];
        int res1 = nums[0];
        int res2 = nums[0];
        for (int i = 1; i < n; ++i) {
            int tmx = mx, tmn = mn;
            mx = max({nums[i], nums[i]*tmx, nums[i]*tmn});//当把nums[i]算入乘积内时，[0,i]范围内的最大连续乘积
            mn = min({nums[i], nums[i]*tmx, nums[i]*tmn});//当把nums[i]算入乘积内时，[0,i]范围内的最小连续乘积
            res1 = max(mx, res1);//记录[0,i]范围内的最大连续乘积
            res2 = min(mn, res2);//记录[0,i]范围内的最小连续乘积
        }
        return pair<int,int>(res1, res2);
    }
};
int main() {
    Solution2 s;
    vector<int> nums = {3,2,0,4,-1};
    cout << s.maxProduct(nums).second;
}