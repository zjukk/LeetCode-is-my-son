#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2, -1);
        if(nums.size() == 0) {
            return v;
        }
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        while (left < right) {
            if(nums[mid] == target)
                break;
            if(nums[mid] > target)
                right = mid;
            else {
                left = mid + 1;
            }
            mid = (left + right) / 2;
        }
        if (nums[mid] != target) {
            return v;
        }
            int i = mid - 1;
            int j = mid + 1;
        while(nums[i] == nums[mid] && i >= 0) {
            i--;
        }
        while(nums[j] == nums[mid] && j <= nums.size() - 1) {
            j++;
        }
        v = {i+1, j-1};
        return v;
    }


    int main() {
        vector<int> v0;
        vector<int> v = {5,7,7,8,8,10};
        v0 = searchRange(v, 5);
        cout << v0[0] << v0[1];
    }