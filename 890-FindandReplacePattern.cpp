#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (int i = 0; i < words.size(); ++i) {
            map<char,char> mp;
            map<char,char> mp2;
            string word = words[i];
            if (pattern.size() != word.size()) continue;
            int j = 0;
            for (; j < pattern.size(); ++j) {
                if (mp.empty() || mp.count(pattern[j]) == 0) {
                    mp.insert({pattern[j], word[j]});
                } else if (mp[pattern[j]] != word[j]){
                    break;
                }
            }
            if (j != pattern.size()) continue;
            int k = 0;
            for (; k < pattern.size(); ++k) {
                if (mp2.empty() || mp2.count(word[k]) == 0) {
                    mp2.insert({word[k],pattern[k]});
                } else if (mp2[word[k]] != pattern[k]) {
                    break;
                }
            }
            if (k == pattern.size()) res.push_back(word);
        }
        return res;
    }
};
class Solution2 {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        string nor = normalize(pattern);
        for (int i = 0 ; i < words.size(); ++i) {
            if (normalize(words[i]) == nor) res.push_back(words[i]);
        }
        return res;
    }
    string normalize(string& s) {
        string res;
        char ch = 'a';
        map<char,char> m;
        for (auto c : s) {
            if (!m.count(c)) {
                m[c] = ch++;
            }
        }
        for (auto c : s) {
            res.push_back(m[c]);
        }
        return res;
    }
};
int main() {
    Solution2 s;
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";
    vector<string> res = s.findAndReplacePattern(words,pattern);
    for (auto s : res) cout << s << endl;
}