#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = 0;
        int minLength = 0;
        int sum = 0;
        while (i < nums.size() && j <= nums.size()) {
            if (sum < s) sum += nums[j++];
            else {
                if (j-i < minLength || minLength == 0) minLength = j - i;
                sum -= nums[i];
                ++i;
                // cout << "i: " << i << " j: " << j << " minLength:" << minLength << " sum:" << sum << endl; 
            }
        }
        return minLength;
    }
};
//Sol2
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int left = 0, right = 0, sum = 0, len = nums.size(), res = len + 1;
        while (right < len) {
            while (sum < s && right < len) {
                sum += nums[right++];
            }
            while (sum >= s) {
                res = min(res, right - left);
                sum -= nums[left++];
            }
        }
        return res == len + 1 ? 0 : res;
    }
};
int main() {
    Solution s;
    vector<int> nums = {5,1,3,5,10,7,4,9,2,8};
    s.minSubArrayLen(15,nums);
}