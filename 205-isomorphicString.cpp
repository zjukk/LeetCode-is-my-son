#include <iostream>
#include <string>
#include <map>

using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> rec, rec2;
        if (s.size() != t.size()) return false;
        rec.insert({s[0],t[0]});
        for (int i = 1; i < s.size(); ++i) {
            if (rec.count(s[i])) {
                if (t[i] != rec[s[i]]) return false;
            } else {
                for (auto it = rec.begin(); it != rec.end(); ++it) {
                    if ((*it).second == t[i]) return false;
                }
                rec.insert({s[i],t[i]});
            }
        }
        return true;
    }
};
class Solution2 {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();//用数组维护2个哈希表
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            //更新哈希表，让2个不同的字符对应到同一个数值，由于初始值全为0，如果 = i，则第一组字符相当于没有更新
            m1[s[i]] = i + 1; 
            m2[t[i]] = i + 1;
        }
        return true;
    }
};
int main() {
    Solution2 s;
    cout << s.isIsomorphic("ab", "aa");
}   