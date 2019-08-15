#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int min_val = INT_MAX, max_val = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > max_val) max_val = nums[i];
            if (nums[i] < min_val) min_val = nums[i];
        }
        if (max_val == min_val) return 0;
        vector<int> mx(nums.size()+1, INT_MIN);
        vector<int> mn(nums.size()+1, INT_MAX);
        mx[nums.size()] = max_val;
        mn[0] = min_val;
        
        for (int i = 0; i < nums.size(); ++i) {
            int index = (nums.size()*(nums[i] - min_val)/(max_val - min_val));//这个很关键
            mx[index] = max(nums[i], mx[index]);
            mn[index] = min(nums[i], mn[index]);
        }
        for (int i : mx) cout << i;
        cout << endl;
        for (int i : mn) cout << i;
        cout << endl;
        int maxGap = 0;
        int pmx = mx[0], pmn = mn[0];
        for (int i = 1; i < nums.size() + 1; ++i) {
            if (mn[i] == INT_MAX) continue;//也可以再定义一个bool hasNumber[]来判断bucket中有没有数
            maxGap = (mn[i]-pmx) > maxGap ? mn[i]-pmx : maxGap;
            pmn = mn[i];
            pmx = mx[i];
        }
        return maxGap;
    }
};

//java
public static int maxGap(int[] nums) {
		if (nums == null || nums.length < 2) {
			return 0;
		}
		int len = nums.length;
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < len; i++) {
			min = Math.min(min, nums[i]);
			max = Math.max(max, nums[i]);
		}
		if (min == max) {
			return 0;
		}
		boolean[] hasNum = new boolean[len + 1];
		int[] maxs = new int[len + 1];
		int[] mins = new int[len + 1];
		int bid = 0;
		for (int i = 0; i < len; i++) {
			bid = bucket(nums[i], len, min, max);
			mins[bid] = hasNum[bid] ? Math.min(mins[bid], nums[i]) : nums[i];
			maxs[bid] = hasNum[bid] ? Math.max(maxs[bid], nums[i]) : nums[i];
			hasNum[bid] = true;
		}
		int res = 0;
		int lastMax = maxs[0];
		int i = 1;
		for (; i <= len; i++) {
			if (hasNum[i]) {
				res = Math.max(res, mins[i] - lastMax);
				lastMax = maxs[i];
			}
		}
		return res;
	}

	public static int bucket(long num, long len, long min, long max) {
		return (int) ((num - min) * len / (max - min));
	}

int main() {
    Solution s;
    vector<int> nums = {3,1,100};
    cout << s.maximumGap(nums);
}