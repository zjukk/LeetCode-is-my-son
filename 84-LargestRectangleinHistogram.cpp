#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <limits>
using namespace std;
//O(N)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int cur = st.top(); st.pop();
                res = max(res, heights[cur] * (st.empty() ? i : (i - st.top() - 1))); //i - st.top() - 1 不能替换成cur,栈顶的元素记录了历史最小下标，因此不需要再考虑元素相等的情况了。
            }
            st.push(i);
        }
        return res;
    }
};
//O(N2)
class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (i + 1 < heights.size() && heights[i+1] > heights[i]) continue;
            int minH = heights[i];
            int area = 0;
            for (int j = i; j >= 0; --j) {
                minH = min(minH, heights[j]);
                area = minH*(i - j + 1);
                res = max(res, area);
            }
            
        }
        return res;
    }
};
//Wrong Sol counter-example is [5,4,1,2]
class Solution3 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        heights.push_back(0);
        int minH = INT_MAX;
        int size = heights.size();
        for (int i = 0; i < heights.size(); ++i) {
            if (i != size - 1) 
            minH = min(minH, heights[i]);
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int cur = st.top(); 
                res = max(res, heights[cur] * (i - cur)); //wrong
                if (heights[st.top()] == heights[i]) break;
                st.pop();
            }
            st.push(i);
        }
        //cout << minH;
        return max(res, minH*(size-1));
    }
};
int main() {
    Solution3 s;
    vector<int> heights = {5,4,1,2};
    cout << s.largestRectangleArea(heights);
}