#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> graph(numCourses);
        vector<int> in(numCourses, 0);
        for (auto a : prerequisites) {
            graph[a.second].push_back(a.first);
            ++in[a.first];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0)  {
                q.push(i);
                res.push_back(i);
            }            
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto a : graph[t]) {
                --in[a];
                if (in[a] == 0) {
                    q.push(a);
                    res.push_back(a);
                }
            }
        }
        for (auto a : in) {
            if (a != 0) return {};
        }
        return res;
    }
};