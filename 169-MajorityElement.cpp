#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(nums[i])) {
                ++m[nums[i]];
            } else {
                m.insert({nums[i],1});
            }
            if (m[nums[i]] > nums.size()/2) return nums[i];
        }
    }
};
//sort
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
//Randomization
class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        while (1) {
            int index = rand() % nums.size();
            int candidate = nums[index];
            if (count(nums, candidate) > nums.size()/2) return candidate;
        }
    }
    int count(vector<int>& nums, int a) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == a)
                ++cnt;
        }
        return cnt;
    }
};
//Divide and Conquer
class Solution4 {
public:
    int majorityElement(vector<int>& nums) {
        return process(nums, 0, nums.size()-1);
    }
    int process(vector<int>& nums, int lo, int hi) {
        if (lo == hi) return nums[lo];
        int mid = lo + (hi-lo)/2;
        int left = process(nums, lo, mid);
        int right = process(nums, mid+1, hi);
        if (left == right) return left;
        int lcnt = count(nums, left, lo, hi);
        int rcnt = count(nums, right, lo, hi);
        return lcnt > rcnt ? left : right;
    }
    int count(vector<int>& nums, int num, int a, int b) {
        int cnt = 0;
        for (int i = a; i <= b; ++i) {
            if (nums[i] == num)
                ++cnt;
        }
        return cnt;
    }
};
//Boyer-Moore Voting Algorithm
class Solution5 {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int candidate = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (cnt == 0) candidate = nums[i];
            nums[i] == candidate ? ++cnt : --cnt;
        }
        return candidate;
    }
};
int main() {
    Solution5 s;
    vector<int> nums = {2,2,3,2,2,3,3};
    cout << s.majorityElement(nums);
}