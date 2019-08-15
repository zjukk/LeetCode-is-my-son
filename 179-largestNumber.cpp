#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// static bool func(const string& s1, const string& s2) {
//     int i;
//     if (s1.size() == s2.size()) return s1 > s2;
//     for (i = 0; i < s1.size() && i < s2.size(); i++) {
//         if (s1[i] < s2[i]) {
//             return false;
//         } else if (s1[i] > s2[i]) {
//             return true;
//         }
//     }   
//     int cmp = s1[i-1];
//     if (i == s1.size()) {
//         while(i < s2.size()) { 
//             if(s2[i] < cmp) return true;
//             ++i;
//         }
//         return false;
//     }
//     if (i == s2.size()) {
//         while(i < s1.size()) { 
//             if(s1[i] < cmp) return false;
//             ++i;
//         }
//         return true;
//     }

// }
// string largestNumber(vector<int>& nums) {
//     string ans;
//     bool isAllZero = true;
//     vector<string> v;
//     for (auto &a : nums) {
//         if (a != 0) isAllZero = false;
//         v.push_back(to_string(a));
//     }
//     if (isAllZero) return string("0");
//     sort(v.begin(), v.end(), func);
    
//     for (auto &s : v) {
//         ans += s;
//     }
//     return ans;
// }
//runtime error
class Solution {
public:
    static bool cmp(const int& a, const int& b) {
        string s1 = to_string(a);
        string s2 = to_string(b);
        if (s1.size() < s2.size()) {
            int i;
            for (i = 0; i < s1.size(); ++i) {
                if (s1[i] > s2[i]) return true;
                if (s1[i] < s2[i]) return false;
            }
            for (int j = i; j < s2.size(); ++j) {
                if (s1[i-1] > s2[j]) return true;
                if (s1[i-1] < s2[j]) return false;
            }
            return true;
        } else {//分界
            int i;
            for (i = 0; i < s2.size(); ++i) {
                if (s1[i] > s2[i]) return true;
                if (s1[i] < s2[i]) return false;
            }
            for (int j = i; j < s1.size(); ++j) {
                if (s1[j] > s2[i-1]) return true;
                if (s1[j] < s2[i-1]) return false;
            }
        }
        return true;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        if (nums[0] == 0) return "0";
        string res;
        for (int i = 0; i < nums.size(); ++i) {
            res += to_string(nums[i]);
        }
        return res;
    }
};

class Solution2 {
public:
    static bool cmp(const int& a, const int& b) {
        string x = to_string(a);
        string y = to_string(b);
        return x+y > y+x ;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        if (nums[0] == 0) return "0";
        string res;
        for (int i = 0; i < nums.size(); ++i) {
            res += to_string(nums[i]);
        }
        return res;
    }
};
class Solution3 {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int a, const int b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        if (nums[0] == 0) return "0";
        string res;
        for (int i = 0; i < nums.size(); ++i) {
            res += to_string(nums[i]);
        }
        return res;
    }
};
int main() {
    Solution3 s;
    // vector<int> nums = {3,30,34,5,9};
    vector<int> nums = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    cout << s.largestNumber(nums);
    // cout << s.cmp(30, 3);
}