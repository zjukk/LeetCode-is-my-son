#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int L = 0;
        int R = 0;
        // vector<bool> occur(26,false);
        map<char, int> m;
        for (int i = 0; i < t.size(); ++i) {
            m.insert({t[i], -1});
        }
        int len = 0;
        while (R < s.size()) {
            if (m.find(s[R]) != m.end()) {
                m[s[R]] = true;
                if (isAll) {
                    len = R - L + 1;
                    
                }
            }
        }
    }
    bool isAll(map<int, bool>& m) {
        for (auto it = m.begin(); it != m.end(); ++it) {
            if ((*it).second == false) return false;
        }
        return true;
    }
};