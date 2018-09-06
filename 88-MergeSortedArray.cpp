#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m; i < m+n; ++i) {
            nums1[i] = nums2[i-m];
        }
        sort(nums1.begin(), nums1.end());
    }
};
class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, k = 0;
        vector<int> nums3(m+n);
        while (i < m && j < n) {
            nums3[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
        }
        while (i < m) nums3[k++] = nums1[i++];
        while (j < n) nums3[k++] = nums2[j++];
        for (int i = 0; i < m+n; ++i) {
            nums1[i] = nums3[i];
        }
    }
};
class Solution3 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;
        while (i >= 0 && j >= 0) {
            nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
int main() {
    Solution2 s;
    vector<int> nums1 = {4,5,6,0,0,0};
    vector<int> nums2 = {1,2,3};
    s.merge(nums1, 3, nums2, 3);
    for (auto i : nums1) cout << i;
}