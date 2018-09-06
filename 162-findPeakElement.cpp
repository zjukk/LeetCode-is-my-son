#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int len = nums.size();
    if(len == 1)
        return 0;
    if(nums[0] > nums[1]) return 0;
    if(nums[len-1] > nums[len-2]) return len-1;
    int left = 0;
    int right = len - 1;
    int mid = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
        return mid;
        nums[mid] > nums[mid+1] ? right = mid : left = mid + 1;
    }
}

int main() {
    vector<int> nums = {1,2,3,1};
    cout << findPeakElement(nums);
}