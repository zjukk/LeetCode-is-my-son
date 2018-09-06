#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int L = 0;
        int R = nums.size() - 1;
        int mid;
        while (L <= R) {
            mid = (L + R) / 2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                break;
            } else if (nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]) {
                mid--;
                break;
            } else if (nums[mid] > nums[0]) {
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        int pivot = mid;
        if (target >= nums[0] && target <= nums[pivot]) {
            L =  0;
            R = pivot;
            while (L <= R) {
                mid = (L + R) / 2;
                if (nums[mid] == target) return mid;
                else if (nums[mid] > target) R = mid - 1;
                else L = mid + 1;
            }
        } else if (target >= nums[pivot + 1] && target <= nums.back()){
            L = pivot + 1;
            R = nums.size() - 1;
            while (L <= R) {
                mid = (L + R) / 2;
                if (nums[mid] == target) return mid;
                else if (nums[mid] > target) R = mid - 1;
                else L = mid + 1;
            }
        }
        return -1;
    }
};

class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;
        int mid;
        while (L <= R) {
            mid = (L+R)/2;
            if(nums[mid] == target) return mid;
            if (nums[mid] > nums[R]) {
                if (target >= nums[L] && target <= nums[mid-1]) R = mid - 1;
                else L = mid + 1;
            } else {
                if (target >= nums[mid + 1] && target <= nums[R]) L = mid + 1;
                else R = mid - 1;
            }
        }
        return -1;
    }
};
int main() {
    Solution2 s;
    vector<int> nums = {4,5,6,7,0,1,2};
    // s.search(nums, 2);
    cout << s.search(nums, 0);
}