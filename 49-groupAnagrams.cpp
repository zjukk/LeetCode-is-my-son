#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

//my version : time exceeded
    bool isAnagrams(string s1, string s2) {
        if (s1.size() != s2.size())
        return false;
        if (s1 == "" && s2 == "")
        return true;
        m<char, int> m1, m2;
        for (int i = 0; i < s1.size(); i++) {
            if(m1.find(s1[i]) == m1.end())
            m1.insert(pair<char, int>(s1[i],1));
            else m1[s1[i]]++;
        }
        for (int i = 0; i < s2.size(); i++) {
            if(m2.find(s2[i]) == m2.end())
            m2.insert(pair<char, int>(s2[i],1));
            else m2[s2[i]]++;
        }
        if(m1 == m2)
        return true;
        else 
        return false;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ans;
        if (strs.size() == 0) return ans;
        for (int i = 0; i < strs.size(); i++) {
            vector<string> v = {strs[i]};
            for (int j = i + 1; j < strs.size(); j++) {
                if(isAnagrams(strs[i],strs[j])){
                    v.push_back(strs[j]);
                    strs.erase(strs.begin() + j);
                    j--;
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
    //sol2: sorted string 
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ans;
        if (strs.size() == 0) return ans;
        map<string, vector<string>> m;
        // for (int i = 0; i < strs.size(); i++) {
        //     string copy = strs[i];
        //     sort(copy.begin(), copy.end());
        //     if (m.find(copy) == m.end()) {
        //         vector<string> help = {strs[i]};
        //         m.insert(pair<string, vector<string>>(copy, help));
        //         continue;
        //     }
        //     m[copy].push_back(strs[i]);
        // }
                //optimization:
        for (string s : strs) {
            string copy = s;
            sort(copy.begin(), copy.end());
            if (m.find(copy) == m.end()) {
                vector<string> help;
                m.insert(pair<string, vector<string>>(copy, help));
            }
            m[copy].push_back(s);
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            ans.push_back((*it).second);
        }
        return ans;
    }