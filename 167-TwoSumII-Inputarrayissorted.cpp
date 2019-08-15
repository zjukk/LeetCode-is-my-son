#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;
//brute force time limit excessed
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for (int i = 0; i < numbers.size() - 1; ++i) {
            for (int j = i + 1; j < numbers.size(); ++j) {
                if (numbers[i] + numbers[j] == target) {
                    res.push_back(i+1);
                    res.push_back(j+1);
                    return res;
                }
            }
        }
        return {};
    }
};
//hash map
class Solution2 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        unordered_map<int, int> ump;
        for (int i = 0; i < numbers.size(); ++i) {
            int comp = target - numbers[i];
            if (ump.find(comp) != ump.end()) {
                res.push_back(ump[comp]);
                res.push_back(i+1);
                return res;
            } else {
                ump.insert({numbers[i], i+1});
            }
        }
        return {};
    }
};
//双指针
class Solution3 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                return {left+1,right+1};
            } else if (numbers[left] + numbers[right] < target) {
                ++left;
            } else {
                --right;
            }
        }
        return {};
    }
};
int main() {
    Solution3 s;
    vector<int> numbers = {2,7,11,15};
    vector<int> res = s.twoSum(numbers, 9);
    for (int i : res) cout << i;
}