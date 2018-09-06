#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
class Solution {
public:
//去重复
    vector<int> process(vector<int>& nums) {
        set<int> st;
        vector<int> res;
        for (int i : nums) {
            if (st.find(i) == st.end()) {
                st.insert(i);
                res.push_back(i);
            }
        }
        return res;
    }
    bool search(vector<int>& nums, int target) {
        nums = process(nums);
        int L = 0;
        int R = nums.size() - 1;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] <= nums[R]) {
                if (target <= nums[R] && target >= nums[mid]) L = mid + 1;
                else R = mid - 1;
            } else {
                if (target <= nums[mid] && target >= nums[L]) R = mid - 1;
                else L = mid + 1;
            }
        }
        return false;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1,1,3,1};
    cout << s.search(nums, 3);
}
