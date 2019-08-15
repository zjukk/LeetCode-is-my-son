#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) return false;
        set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            s.insert(nums[i]);
        }
        cout << nums.size() << " " << s.size();
        return nums.size() != s.size();
    }
};
int main() {
    Solution s;
    vector<int> nums = {3,1};
    cout << s.containsDuplicate(nums);
}