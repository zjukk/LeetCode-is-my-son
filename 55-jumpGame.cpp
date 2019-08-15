#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//dfs:待完善
// bool dfs(vector<int>& nums, int pre, int cur) {
//         if (cur >= nums.size() - 1)
//         return true;
        
//         for (int i = cur; i >= pre; --i) {
//             if (nums[i] != 0 && dfs(nums, i, i+nums[i])) {
//                 return true;
//             }
//         }
//         return false;
//     }  
// bool canJump(vector<int>& nums) {
//     if (nums.size() <= 1)
//     return true;
//     if(nums[0] == 0)
//     return false;
//     return dfs(nums, 0, 0);
    
// }
bool canJump(vector<int>& nums) {
    int reach = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        if (reach >= n-1 || i > reach) break;
        reach = max(reach, i + nums[i]);
    }
    return reach >= n-1;
}
bool canJump2(vector<int>& nums) {
    int n = nums.size();
    vector<bool> v(n, false);
    v[0] = true;
    for (int i = 1; i < n; ++i) {
        if (v[i-1] && nums[i-1] > 0) v[i] = true;
    }
    return v[n-1];
}

int main() {
    vector<int> nums = {3,2,1,0,2,4};
    cout << canJump2(nums);
}