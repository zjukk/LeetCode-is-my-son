#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
class Solution {
public:
    // int trap(vector<int>& height) {
    //     if (height.size() < 3) return 0;
    //     stack<pair<int, int>> s;
    //     int res = 0;
    //     s.push({0, height[0]});
    //     pair<int,int> temp;
    //     for (int i = 1; i < height.size(); i++) {
    //             while (!s.empty() && height[i] > s.top().second) {//!s.empty()的判断很重要
    //                 temp = s.top();
    //                 s.pop();
    //                 if (!s.empty())
    //                 res += (i - s.top().first - 1)*(min(height[i], s.top().second) - temp.second);
    //         }
    //             s.push({i, height[i]});  
    //     }
    //     return res;
    // }
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        stack<int> s;
        int res = 0;
        s.push(0);
        int temp;
        for (int i = 1; i < height.size(); i++) {
                while (!s.empty() && height[i] > height[s.top()]) {//!s.empty()的判断很重要
                    temp = s.top();
                    s.pop();
                    if (!s.empty())
                    res += (i - s.top() - 1) * (min(height[i],height[s.top()]) - height[temp]);
            }
                s.push(i);  
        }
        return res;
    }
};
    //sol2:Brute force
    int trap2(vector<int>& height)
    {  
        int ans = 0;
        int size = height.size();
        for (int i = 1; i < size - 1; i++) {
            int maxRight = 0, maxLeft = 0;
            for (int j = i; j < size - 1; j++) {
                maxRight = max(maxRight, height[j]);
            }
            for (int j = i; j >= 0; j--) {
                maxLeft = max(maxLeft, height[j]);
            }
            ans += min(maxRight, maxLeft) - height[i];
        }
        return ans;
    }
    //Sol3: Dynamic Programming
    int trap3(vector<int>& height)
    {  
        int ans = 0;
        int size = height.size();
        vector<int> maxLeft(size, 0);
        vector<int> maxRight(size, 0);
        maxRight[size - 1] = height[size - 1];
        maxLeft[0] = height[0];
        for (int i = 1; i < size; ++i) {
            maxLeft[i] = max(maxLeft[i-1], height[i]);
        }
        for (int i = size - 2; i >= 0; --i) {
            maxRight[i] = max(maxRight[i+1], height[i]);
        }
        for (int i = 1; i < size - 1; ++i) {
            ans += min(maxRight[i], maxLeft[i]) - height[i];
        }
        return ans;
    }
int main() {
    Solution s;
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    // cout << s.trap(v);
    cout << trap3(v);
}