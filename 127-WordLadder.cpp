#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
//Time limit exceeded dfs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        string cur = beginWord;
        vector<int> res;
        int n = wordList.size();
        vector<bool> visited(n, false);
        int ans = 0;
        dfs(cur, res, wordList, endWord, visited, 1);
        if (res.empty()) return ans;
        sort(res.begin(), res.end());
        ans = res[0];
        return ans;
    }
    void dfs(string& cur, vector<int>& res, vector<string>& wordList, string& endWord, 
    vector<bool>& visited, int cnt) {
        if (cur == endWord) {
            res.push_back(cnt);
            --cnt;
            return;
        }
        for (int i = 0; i < wordList.size(); ++i) {
            if (isOK(cur, wordList[i]) && !visited[i]) {
                visited[i] = true;
                dfs(wordList[i], res, wordList, endWord, visited, cnt+1);
                visited[i] = false;
            }
        }
    }
    bool isOK(string a, string b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) ++cnt;
        }
        return cnt == 1;
    }
};
//bfs
class Solution2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        unordered_map<string, int> pathCnt{{beginWord, 1}};
        queue<string> q{{beginWord}};
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            for (int j = 0; j < word.size(); ++j) {
                string newWord = word;
                for (char c = 'a'; c <= 'z'; ++c) {
                    newWord[j] = c;
                    if (wordSet.count(newWord) && newWord == endWord) return pathCnt[word] + 1;
                    if (wordSet.count(newWord) && !pathCnt.count(newWord)) {
                        pathCnt[newWord] = pathCnt[word] + 1;
                        q.push(newWord);
                    }
                }
            }
        }
        return 0;
    }
};
//改良版 BFS，去掉 map，用queue层数记录长度
class Solution3 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q{{beginWord}};
        int res = 0;
        while (!q.empty()) {
            ++res;
            int size = q.size();
            for (int k = 0; k < size; ++k) {
                string word = q.front(); q.pop(); 
                if (word == endWord) return res;
                    for (int j = 0; j < word.size(); ++j) {
                    string newWord = word;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        newWord[j] = c;
                        if (wordSet.count(newWord) && newWord != word) {
                            q.push(newWord);
                            wordSet.erase(word);//已经访问过的就不重复访问
                        }
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution3 s;
    string beginWord = "hit";
    string endWord = "cog";
    // vector<string> wordList = {"hot","dot","dog","lot","log"};
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << s.ladderLength(beginWord, endWord, wordList);
}
// 解题思路：
// 当拿到题就懵逼的我们如何才能找到一个科学的探索解题的路径呢，那就是先别去管代码实现，
// 如果让我们肉身解题该怎么做呢？让你将 'hit' 变为 'cog'，那么我们发现这两个单词没有一个相同的字母，
// 所以我们就尝试呗，博主会先将第一个 'h' 换成 'c'，看看 'cit' 在不在字典中，发现不在，
// 那么把第二个 'i' 换成 'o'，看看 'hot' 在不在，发现在，完美！然后尝试 'cot' 或者 'hog'，发现都不在，
// 那么就比较麻烦了，我们没法快速的达到目标单词，需要一些中间状态，但我们怎么知道中间状态是什么。
// 简单粗暴的方法就是brute force，遍历所有的情况，我们将起始单词的每一个字母都用26个字母来替换，
// 比如起始单词 'hit' 就要替换为 'ait', 'bit', 'cit', .... 'yit', 'zit'，将每个替换成的单词都在字典中查找一下，
// 如果有的话，那么说明可能是潜在的路径，要保存下来。那么现在就有个问题，比如我们换到了 'hot' 的时候，
// 此时发现在字典中存在，那么下一步我们是继续试接下来的 'hpt', 'hqt', 'hrt'... 
// 还是直接从 'hot' 的首字母开始换 'aot', 'bot', 'cot' ... 这实际上就是BFS和DFS的区别，到底是广度优先，还是深度优先。
// 讲到这里，不知道你有没有觉得这个跟什么很像？对了，跟迷宫遍历很像啊，你想啊，迷宫中每个点有上下左右四个方向可以走，
// 而这里有26个字母，就是二十六个方向可以走，本质上没有啥区别啊！如果熟悉迷宫遍历的童鞋们应该知道，
// 应该用BFS来求最短路径的长度，这也不难理解啊，DFS相当于一条路走到黑啊，你走的那条道不一定是最短的啊。
// 而BFS相当于一个小圈慢慢的一层一层扩大，相当于往湖里扔个石头，一圈一圈扩大的水波纹那种感觉，
// 当水波纹碰到湖上的树叶时，那么此时水圈的半径就是圆心到树叶的最短距离。脑海中有没有浮现出这个生动的场景呢？

// 明确了要用BFS，我们可以开始解题了，为了提到字典的查找效率，我们使用HashSet保存所有的单词。
// 然后我们需要一个HashMap，来建立某条路径结尾单词和该路径长度之间的映射，并把起始单词映射为1。
// 既然是BFS，我们需要一个队列queue，把起始单词排入队列中，开始队列的循环，取出队首词，然后对其每个位置上的字符，
// 用26个字母进行替换，如果此时和结尾单词相同了，就可以返回取出词在哈希表中的值加一。
// 如果替换词在字典中存在但在哈希表中不存在，则将替换词排入队列中，并在哈希表中的值映射为之前取出词加一。
// 如果循环完成则返回0