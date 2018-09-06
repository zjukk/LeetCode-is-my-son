#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#include <string>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int minn = INT_MIN + 1 ;
    int maxn = INT_MAX;
    int fix, L, R;
    int cmp;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
        fix = nums[i];
        L = i + 1;
        R = nums.size() - 1;
        cmp = fix + nums[L] + nums[R] - target; 
        while (L < R) {
            if (cmp > 0) {
                maxn = min(maxn, cmp);
                cmp = fix + nums[L] + nums[--R] - target;
            } else if (cmp < 0) {
                minn = max(minn, cmp);
                cmp = fix + nums[++L] + nums[R] - target;
            } else {
                return target;
            }

        }    
    }
    return maxn > abs(minn) ? target + minn : target + maxn;
}
int main() {
    vector<int> nums = {0,1,2};
    cout << threeSumClosest(nums, 3);
}