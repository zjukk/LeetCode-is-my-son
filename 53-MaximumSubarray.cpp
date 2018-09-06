#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int L = 0, R = 0;
        int sum = 0;
        int maxsum = INT_MIN;//初始化一定要单独给初值，不然会出现未定义情况
        while (R < nums.size()) {
            sum += nums[R];
            maxsum = max(maxsum, sum);
            if(sum < 0) {
                L++;
                R = L;
                sum = 0;
            } else ++R;
        }
        return maxsum;
    }
};
int getNum(int n, int m) {
    int** p = new int* [n];
    for (int i = 0; i < n; ++i) {
        p[i] = new int[m];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            p[i][j] = i+j;
        }
    }
    return p[n-1][m-1];
}
int main() {
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    // cout << s.maxSubArray(nums);
    cout << getNum(5,6);
}