#include <iostream>
#include <vector>

using namespace std;
//dp
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size() == 1 ? nums[0] : 0;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp.back();
    }
};
class Solution2 {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n == 1) return nums[0];
        int pre = nums[0];
        int cur = max(nums[0],nums[1]);
        int next = cur;
        for (int i = 2; i < n; ++i) {
            next = max(pre + nums[i], cur);
            pre = cur;
            cur = next;
        }
        return next;
    }
};
class Solution3 {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size() == 1 ? nums[0] : 0;
        int a = 0, b = 0;//a和b分别更新保存奇数和偶数位置处的最大robmoney
        for (int i = 0; i < nums.size(); ++i) {
            //cur在奇数位置时更新a
            if (i % 2 == 0) {
                a = max(a + nums[i], b);
            } else {
                b = max(b + nums[i], a);
            }
        }
        return max(a,b);
    }
};
int main() {
    Solution2 s;
    vector<int> nums = {2,1,1,2};
    cout << s.rob(nums);
}