#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> ans;
    vector<int> v;
    int a, b, c;
    for (int i = 0; i < nums.size(); i++) {
        a = nums[i];
        for (int j = 0; j < nums.size(); j++) {
            b = nums[j];
            if(j == i) continue;
            for (int k = 0; k < nums.size(); k++) {
                c = nums[k];
                if(k == i || k == j || a+b+c != 0) continue;
                v = {a,b,c};
                sort(v.begin(), v.end());
                ans.insert(v);
            }
        }
    }
    vector<vector<int>> res(ans.begin(),ans.end());
    return res;
}
//better resolution 先排序 再寻找，用set去除重复结果，fix到正数后不用接着往下找
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    set<vector<int>> ans;
    vector<int> v;
    int fix;
    int L = 0;
    int R = nums.size() - 1;
    for (int i = 0; i < nums.size(); i++) {
        fix = nums[i];
        if (fix > 0) break;
        L = i + 1;
        R = nums.size() - 1;
        while (L < R) {
            if (nums[L] + nums[R] + fix < 0){
                ++L;
            }
            else if (nums[L] + nums[R] + fix > 0){
                --R;
            } else {
                v = {nums[i], nums[L], nums[R]};
                ans.insert(v);
                ++L;
                --R;
            }
        }
    }
    vector<vector<int>> res(ans.begin(),ans.end());
    return res;
}


