class Solution {
    vector<vector<int>> createAdjacencyList(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        return adj;
    }
    bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &adj) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto adjNode : adj[node]) {
            if (!vis[adjNode]) {
                if (dfs(adjNode, vis, pathVis, adj) == false) {
                    return false;
                }
            } else if (vis[adjNode] && pathVis[adjNode]) {
                return false;
            }
        }

        pathVis[node] = 0;

        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj = createAdjacencyList(numCourses, prerequisites);

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathVis, adj) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};