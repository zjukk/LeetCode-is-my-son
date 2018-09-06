#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

static bool func(const string& s1, const string& s2) {
    int i;
    if (s1.size() == s2.size()) return s1 > s2;
    for (i = 0; i < s1.size() && i < s2.size(); i++) {
        if (s1[i] < s2[i]) {
            return false;
        } else if (s1[i] > s2[i]) {
            return true;
        }
    }   
    int cmp = s1[i-1];
    if (i == s1.size()) {
        while(i < s2.size()) { 
            if(s2[i] < cmp) return true;
            ++i;
        }
        return false;
    }
    if (i == s2.size()) {
        while(i < s1.size()) { 
            if(s1[i] < cmp) return false;
            ++i;
        }
        return true;
    }

}
string largestNumber(vector<int>& nums) {
    string ans;
    bool isAllZero = true;
    vector<string> v;
    for (auto &a : nums) {
        if (a != 0) isAllZero = false;
        v.push_back(to_string(a));
    }
    if (isAllZero) return string("0");
    sort(v.begin(), v.end(), func);
    
    for (auto &s : v) {
        ans += s;
    }
    return ans;
}
