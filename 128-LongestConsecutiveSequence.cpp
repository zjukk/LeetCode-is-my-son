#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <unordered_set>
using namespace std;

//此题相等的两个数不在连续序列的长度中
//超出空间 bucket_sort
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        for (int i : nums) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
        int n = mx - mn + 1;
        vector<bool> bucket(n, false);
        for (int i : nums) {
            bucket[i-mn] = true;
        }
        int res = 0;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (bucket[i]) {
                ++cur;
            } else {
                res = max(res, cur);
                cur = 0;
            }
        }
        return res;
    }
};
//brute force -- Java
class Solution {
    private boolean arrayContains(int[] arr, int num) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == num) {
                return true;
            }
        }

        return false;
    }
    public int longestConsecutive(int[] nums) {
        int longestStreak = 0;

        for (int num : nums) {
            int currentNum = num;
            int currentStreak = 1;

            while (arrayContains(nums, currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }

            longestStreak = Math.max(longestStreak, currentStreak);
        }

        return longestStreak;
    }
}
//hash_set
// Complexity Analysis

// Time complexity : O(n).

// Although the time complexity appears to be quadratic due to the while loop nested within the for loop, 
// closer inspection reveals it to be linear. 
// Because the while loop is reached only when currentNum marks the beginning of a sequence 
// (i.e. currentNum-1 is not present in nums), 
// the while loop can only run for nn iterations throughout the entire runtime of the algorithm. 
// This means that despite looking like O(n \cdot n)O(n⋅n) complexity, 
// the nested loops actually run in O(n + n) = O(n) time. 
// All other computations occur in constant time, so the overall runtime is linear.

// Space complexity : O(n).

// In order to set up O(1)O(1) containment lookups, 
// we allocate linear space for a hash table to store the O(n) numbers in nums. 
// Other than that, the space complexity is identical to that of the brute force solution.

class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());//用hash_set查询的效率为O(1)
        int mx = 0;
        for (auto it = s.begin(); it != s.end(); ++it) {
            int cur = *it;
                if (!s.count(cur-1)) {
                    int cnt = 0;
                    while (s.count(cur)) {
                    ++cnt;
                    ++cur;
                }
                mx = max(mx, cnt);
            }
        }
        return mx;
    }
};

class Solution3 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());//用hash_set查询的效率为O(1)
        int res = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (s.count(nums[i])) {
                s.erase(nums[i]);
                int pre = nums[i] - 1;
                int next = nums[i] + 1;
                while (s.count(pre)){
                    s.erase(pre--);
                }
                while (s.count(next)){
                    s.erase(next--);
                }
                res = max(res, next - pre - 1);
            }
        }
        return res;
    }
};

int main() {
    Solution3 s;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << s.longestConsecutive(nums);
}