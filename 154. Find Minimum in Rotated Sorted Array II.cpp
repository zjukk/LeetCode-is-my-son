#include <iostream>
#include <vector>

using namespace std;
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else if (nums[mid] > nums[right]) {
                left = mid;
            } else {
                right--;
            }
        }
        return min(nums[left], nums[right]);
    }
};