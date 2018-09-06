#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
//sol:1pass hash
vector<int> twoSum(vector<int> nums, int target){
    map<int, int> m;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        int comp = target - nums[i];
        if (m.find(comp) != m.end()) {
            ans.push_back(m[comp]);
            ans.push_back(i);
            return ans;
        }
        m.insert(pair<int, int>(nums[i], i));
    }
    return ans;
}