#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;


Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mp;
        queue<UndirectedGraphNode *> q;
        UndirectedGraphNode * newNode = new UndirectedGraphNode(node->label);
        mp.insert({node, newNode});
        q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode *top = q.front();
            for (auto neighborNode : top->neighbors) {
                if (mp.count(neighborNode) == 0) {
                    q.push(neighborNode);
                    UndirectedGraphNode* newNeighbors = new UndirectedGraphNode(neighborNode->label);
                    mp.insert({neighborNode, newNeighbors});
                }
                mp[top]->neighbors = top->neighbors;
            }
            q.pop();
        }
        return mp[node];
    }
};