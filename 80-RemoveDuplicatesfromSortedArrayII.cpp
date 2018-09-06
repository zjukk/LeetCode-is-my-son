#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int cnt = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (cnt > 2) {nums.erase(nums.begin()+i);--cnt;--i;};
            if (i+1 < nums.size() && nums[i+1] == nums[i]) {
                ++cnt;
            } else {
                cnt = 1;
            }
            // for (int i : nums) cout << i;
            // cout << endl;
        }
        return nums.size();
    }
};
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int pre = 0, cur = 1, cnt = 1;
        while (cur < n) {
            if (nums[pre] == nums[cur] && cnt == 0) {
                ++cur;
            }
            else {
                if (nums[pre] == nums[cur]) --cnt;
                else cnt = 1;
                nums[++pre] = nums[cur++];
            }
        }
        return pre+1;
    }
};
int main() {
    Solution2 s;
    vector<int> nums = {1,1,1};
     cout <<s.removeDuplicates(nums);
    // for (int i : nums) cout << i;
}