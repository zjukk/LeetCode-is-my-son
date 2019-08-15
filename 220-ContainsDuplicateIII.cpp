#include <iostream>
#include <map>

using namespace std;
//brute force
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j <= i + k && j < nums.size(); ++j) {
                long long a = nums[i];
                long long b = nums[j];
                if ((b - a >= 0 && b - a <= t) || (b - a < 0 && a - b <= t)) 
                return true;
            }
        }
        return false;
    }
};
//using map
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int j = 0;
        map<long long, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - j > k) m.erase(nums[j++]);
            auto a = m.lower_bound((long long)nums[i] - t);
            if (a != m.end() && abs(a->first - nums[i]) <= t) return true;
            m[nums[i]] = i;
        }
        return false;
    }
};
