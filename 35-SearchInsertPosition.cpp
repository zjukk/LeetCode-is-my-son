#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) return i;
            if (nums[i] > target) {
                return i;
            }
        }
        return nums.size();
    }
};
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) return i;
            if (nums[i] > target) {
                return i;
            }
        }
        return nums.size();
    }
};
//binary search
class Solution2 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1;
        int mid;
        while (L <= R) {
            mid = (L+R)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) R = mid-1;
            else L = mid + 1;
        }
        return nums[mid] > target ? mid : mid + 1;
    }
};