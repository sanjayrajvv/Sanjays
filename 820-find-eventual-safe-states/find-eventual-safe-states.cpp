#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rGraph(n);

        // Reverse the graph
        for (int node = 0; node < n; ++node) {
            for (int adj : graph[node]) {
                rGraph[adj].push_back(node);
            }
        }

        // Calculate in-degrees
        vector<int> inDegree(n, 0);
        for (int node = 0; node < n; ++node) {
            for (int adj : rGraph[node]) {
                inDegree[adj]++;
            }
        }

        // Topological sort using queue
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int adjNode : rGraph[node]) {
                inDegree[adjNode]--;
                if (inDegree[adjNode] == 0) {
                    q.push(adjNode);
                    
                }
            }
        }

        // Sort the answer list
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//Reverse the graph
//Calculate inGegree of all nodes
//Do toposort from the nodes having inDegree 0
//Print all nodes which is visited