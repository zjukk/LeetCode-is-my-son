#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j) {
                sum += nums[j] >> i & 1;
            }
            res |= (sum % 3) << i;// |=和+=都可以
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> nums = {0,1,0,1,0,1,99};
    cout << s.singleNumber(nums);
}