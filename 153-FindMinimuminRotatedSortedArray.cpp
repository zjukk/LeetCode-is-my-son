#include <iostream>
#include <vector>

using namespace std;
//同类题目还有33、34、154
class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = nums[0];
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i+1] < nums[i]) {
                res = nums[i+1];
                return res;
            }
        }
        return res;
    }
};
//binarysearch
class Solution2 {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        if (nums[l] < nums[r]) return nums[l];
        else {
            while (l <= r) {
                if (l == r) return nums[l];
                if (r == l + 1) return min(nums[l], nums[r]);
                int mid = (l + r) / 2;
                if (nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]) return nums[mid];
                if (nums[mid] < nums[r]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
    }
};
class Solution3 {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        if (nums[l] < nums[r]) return nums[l];
        else {
            while (r-l > 1) {
                int mid = (l + r) / 2;
                if (nums[mid] < nums[r]) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            return min(nums[l], nums[r]);
        }
    }
};
//fastest solution
class Solution4 {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        if (nums[l] < nums[r]) return nums[l];
        else {
            while (l <= r) {
                if (l == r) return nums[l];
                if (r == l + 1) return min(nums[l], nums[r]);
                int mid = (l + r) / 2;
                if (nums[mid] < nums[mid-1]) return nums[mid];
                if (nums[mid] > nums[mid+1]) return nums[mid+1];
                if (nums[mid] < nums[r]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
    }
};

int main() {
    Solution3 s;
    vector<int> nums = {3,4,5,1,2};
    // cout << s.findMin(nums);
}