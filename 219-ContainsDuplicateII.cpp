#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//不限制对数，可以有多对
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k <= 0) return false;
        for (int i = 0; i < nums.size() - 1; ++i) {
            int j = i + 1;
            for (; j <= i + k && j < nums.size(); ++j) {
                if (nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
};
class Solution2 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k <= 0) return false;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) 
                return true;
            else m[nums[i]] = i;
        }
        return false;
    }
};
//限制条件只能有一对相同的数对
class Solution3 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k <= 0) return false;
        unordered_map<int, int> m;
        int d = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k)  {
                if (d > 0) return false;
                else d = i - m[nums[i]];
            }
            m[nums[i]] = i;
        }
        return d == 0 ? false : d <= k;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1,2,3,1};
    int k = 3;
    cout << s.containsNearbyDuplicate(nums, k);
}