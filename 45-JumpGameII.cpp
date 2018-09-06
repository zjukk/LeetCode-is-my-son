#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
//Time Limit Exceeded
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> cur;
        cur.push_back(nums[0]);
        dfs(nums, ans, cur, 1);
        int minSize = INT_MAX;
        for (auto a : ans) {
            minSize = min(minSize, (int)a.size());
        }
        return minSize-1;
    }
    void dfs(vector<int>& nums, vector<vector<int> >& ans, vector<int>& cur, int level) {
        if(level == nums.size()) {
            ans.push_back(cur);
            return;
        }

        for (int i = level; i < nums.size(); ++i) {
            if (cur.empty() || i <= level - 1 + cur.back()) {
                cur.push_back(nums[i]);
                dfs(nums, ans, cur, i + 1);
                cur.pop_back();
            }
        }
    }
};
//Sol2:my version
class Solution2 {
public:
    int jump(vector<int>& nums) {
        int cur = 0;
        int res = 0;
        int maxJump = -1;
        int index;
        while (cur < nums.size() - 1) {
            for (int i = cur; i <= cur + nums[cur] && i < nums.size(); ++i) {//每次取到最远距离，会有重复计算
                if (i == nums.size() - 1) return ++res;
                if (i + nums[i] > maxJump) {
                    maxJump = i + nums[i];
                    index = i;//记录下能到达最远范围的下标
                }
            }
            cur = index;
            ++res;
        }
       return res;
    }
};
//precise version of Sol2:贪心 贪最远的范围，每步都取到最大范围，然后在这一步的最大范围内，求下一步能到达的最大范围
class Solution3 {
public:
    int jump(vector<int>& nums) {
        int res = 0, i = 0;
        int cur = 0;//当前能达到最远范围的下标
        int pre;//前一次跳跃能到达最远的范围下标
        while (cur < nums.size() - 1) {
            ++res;
            pre = cur;
            for (; i <= pre; ++i) {
                cur = max(cur, i + nums[i]);
            }
            if (cur == pre) return -1; // cur未更新，说明无法达到终点
        }
        return res;
    }
};
//Sol4和Sol3的本质是一样的。都是一遍遍历。
class Solution4 {
public:
    int jump(vector<int>& nums) {
        int res = 0, cur = 0, last = 0;//cur为当前能跳的最大范围
        for (int i = 0; i < nums.size() - 1; ++i) {
            cur = max(cur, i + nums[i]);
            //i到达上一次能跳的最远位置， 需要跳下一次
            if (i == last) {
                ++res;
                last = cur;
                if (last >= nums.size() - 1) break;
            }
        }
        return res;
    }
};
int main() {
    Solution4 s;
    vector<int> v2 = {2,3,0,1,4};
    vector<int> v = {2,9,6,5,7,0,7,2,7,9,3,2,2,5,7,8,1,6,6,6,3,5,2,2,6,3};
    //cout << v.size() <<endl;
   // cout << s.jump(v2);
    int x, y = 0;
    cout << x <<"" <<y;
}