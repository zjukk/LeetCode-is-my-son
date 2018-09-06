#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
void reverse(vector<int>& nums, int start) {
    int i = start;
    int j = nums.size() - 1;
    while(i < j) {
        swap(nums, i, j);
        ++i;
        --j;
    }
}
//myversion:unknown error
void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i-1] < nums[i]) {
                static int k = i;
                for (int j = i + 1; j < nums.size(); j++) {
                    if(nums[j] > nums[i-1]) {
                        k = j;
                    } else {break;}
                }
                swap(nums, i-1, k);
                reverse(nums, i);
                return;
            }
        }
        reverse(nums, 0);
    }
    //sol2:
void nextPermutation2(vector<int>& nums) {
    int i = nums.size() - 2;
    while (i >= 0 && nums[i + 1] <= nums[i]) {
        i--;
    }
    if (i >= 0) {
        int j = nums.size() - 1;
        while (nums[j] <= nums[i]) {
        j--;
    }
    swap(nums, i, j);
    }
    reverse(nums, i+1);
}
    int main() {
        vector<int> v = {1,2,3,4};
        //reverse(v,3);
        //swap(v,0,3);
        nextPermutation2(v);
        for (auto a : v) {
            cout << a << " ";
        }

    }