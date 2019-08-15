#include <iostream>
#include <queue>
#include <vector>

using namespace std;
// This problem is equivalent to finding if a cycle exists in a directed graph. 
// If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
//BFS
// 拓扑排序的核心就是每次找入度为0的点，进入输出队列 ，然后将与此点相连的节点入度减1
// 重复做以上操作。
// 当做n-1 次后还有点没进输出队列 那么这些点就是环上的 
// 因为环上的各点入度都为1 没有0的 就不能更新。
// 也就是说拓扑排序一遍之后，如果是DAG所有点都恰好入队一次
// 如果有环，那么一定存在没有入队的点。

// 我们定义二维数组graph来表示这个有向图，一位数组in来表示每个顶点的入度。
// 我们开始先根据输入来建立这个有向图，并将入度数组也初始化好。
// 然后我们定义一个queue变量，将所有入度为0的点放入队列中（图中的起点，必定是最先学习的课程），然后开始遍历队列，
// 从graph里遍历其连接的点（BFS将相邻每一层的节点都遍历了），每到达一个新节点，将其入度减一，如果此时该点入度为0，
// 则放入队列末尾（视作新的起点）。直到遍历完队列中所有的值，若此时还有节点的入度不为0，
// 则说明环存在，返回false，反之则返回true。
class Solution1 {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> in(numCourses, 0);
        for (auto a : prerequisites) {
            graph[a.second].push_back(a.first);
            ++in[a.first];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto a : graph[t]) {
                --in[a];
                if (in[a] == 0) q.push(a);
            }
        }
        for (auto a : in) {
            if (a != 0) return false;
        }
        return true;
    }
};
//DFS
// 也需要建立有向图，还是用二维数组来建立，和BFS不同的是，我们像现在需要一个一维数组visit来记录访问状态，
// 这里有三种状态，0表示还未访问过，1表示已经访问了，-1表示有冲突。
// 大体思路是，先建立好有向图，然后从第一个门课开始，找其可构成哪门课，
// 暂时将当前课程标记为已访问（冲突），然后对新得到的课程调用DFS递归，直到出现新的课程已经访问过了（说明图内部有环，即冲突了），
// 则返回false，没有冲突的话返回true，然后把标记为已访问的课程置1。
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto a : prerequisites) {
            graph[a.second].push_back(a.first);
        }
        vector<int> visit(numCourses, 0);// 0-unvisited, 1-visited, -1-conflict
        for (int i = 0; i < numCourses; ++i) {
            if (!canFinishDFS(graph, visit, i)) return false;
        }
        return true;
    }
    bool canFinishDFS(vector<vector<int>>& graph, vector<int>& visit, int i) {
        if (visit[i] == -1) return false;
        if (visit[i] == 1) return true;
        visit[i] = -1;
        for (auto a : graph[i]) {
            if (!canFinishDFS(graph, visit, a)) return false;
        }
        visit[i] = 1;
        return true;
    }
};
int main() {
    Solution1 s;
    // vector<pair<int,int>> prerequisites = {{2,1},{3,2},{1,3},{1,4}};
    vector<pair<int,int>> prerequisites = {{1,0},{0,1}};
    // cout << prerequisites[3].first << " ," << prerequisites[3].second;
    cout<< s.canFinish(2,prerequisites);
}