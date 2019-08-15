#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) return;
        vector<int> help;
        for (int i = n-k; i < n; ++i) {
            help.push_back(nums[i]);
        }
        for (int i = 0; i < n-k; ++i) {
            help.push_back(nums[i]);
        }
        for (int i = 0; i < n; ++i) {
            nums[i] = help[i];
        }
    }
};
class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) return;
        // insert(nums.begin(), nums.begin() + n - k, nums.end());//??not work
        nums.insert(nums.begin(), nums.begin() + n - k, nums.end());
        nums.erase(nums.begin()+n, nums.end());
    }
};
int main() {
    Solution2 s;
    vector<int> nums = {1,2,3,4,5,6,7};
    s.rotate(nums, 3);
    for (int i : nums) cout << i;
}