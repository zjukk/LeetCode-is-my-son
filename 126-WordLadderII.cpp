#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q{{beginWord}};
        vector<vector<string>> res;
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                string word = q.front();
                q.pop();
                if (word == endWord) 
                for (int i = 0; i < beginWord.size(); ++i) {
                    string newWord = word;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        newWord[i] = c;
                        if (wordSet.count(newWord) && newWord != word) {
                            q.push(newWord);
                            wordSet.erase(word);
                        }
                    }
                }
            }
        }
    }
};