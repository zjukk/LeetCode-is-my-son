#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int L = 0;
        int R = nums.size() - 1;
        for (int i = 0; i <= R; ++i) {
            if (nums[i] == 2) {
                swach(nums, i--, R--);
            } else if (nums[i] == 0) {
                swach(nums, i, L++);
            } 
        }
    }
    void swach(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1,1,0,1,2,0,2,1,2,0};
    s.sortColors(nums);
    for (int i : nums) cout << i;
}