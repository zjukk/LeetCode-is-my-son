#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();

        if (N1 < N2) return findMedianSortedArrays(nums2, nums1); // Make sure A2 is the shorter one.
        int lo = 0; int hi = 2*N2;

        while (lo <= hi) {
            int mid2 = (lo + hi) / 2; // Try Cut 2
            int mid1 = N1 + N2 - mid2; // Calculate Cut 1 accordingly

            int L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2]; //median is in nums2
            int L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
            int R1 = (mid1 == 2*N1) ? INT_MAX : nums1[mid1/2]; //median is in nums2
            int R2 = (mid2 == 2*N2) ? INT_MAX : nums2[mid2/2];

            if (L1 > R2) lo = mid2 + 1; // A1's lower half is too big; need to move C1 left (C2 right)
            else if (L2 > R1) hi = mid2 - 1;// A2's lower half too big; need to move C2 left.
            else return (max(L1,L2) + min(R1,R2)) / 2.0; // Otherwise, that's the right cut.
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> v1{1,2,3};
    vector<int> v2{4,5,6};
    cout << s.findMedianSortedArrays(v1,v2);
}