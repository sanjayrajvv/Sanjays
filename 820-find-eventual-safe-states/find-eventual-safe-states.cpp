#include <vector>

using namespace std;

class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& pathVisited, vector<int>& check) {
        visited[node] = 1;
        pathVisited[node] = 1;

        // Explore all adjacent nodes
        for (auto adjacentNode : graph[node]) {
            if (!visited[adjacentNode]) {
                if (dfs(adjacentNode, graph, visited, pathVisited, check)) {
                    check[adjacentNode] = 0;
                    return true;
                }
            } else if (pathVisited[adjacentNode]) {
                check[adjacentNode] = 0;
                return true;
            }
        }

        // Mark the current node as safe
        check[node] = 1;
        pathVisited[node] = 0;

        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int numNodes = graph.size();
        vector<int> visited(numNodes, 0);
        vector<int> pathVisited(numNodes, 0);
        vector<int> check(numNodes, 0);

        // Perform DFS from each unvisited node
        for (int i = 0; i < numNodes; ++i) {
            if (!visited[i]) {
                dfs(i, graph, visited, pathVisited, check);
            }
        }

        // Collect all safe nodes
        vector<int> safeNodes;
        for (int i = 0; i < numNodes; ++i) {
            if (check[i] == 1) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};
