class Solution {
    bool dfs(int node, vector<vector<int>>& graph, vector<int> &vis, vector<int> &pathVis, vector<int> &check) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto adjNode : graph[node]) {
            if (!vis[adjNode]) {
                if (dfs(adjNode, graph, vis, pathVis, check) == true) {
                    return true;
                }
            } else if (pathVis[adjNode]) {
                return true;
            }
        }

        check[node] = 1;
        pathVis[node] = 0;

        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n, 0), pathVis(n, 0), check(n, 0), ans;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, pathVis, check);
            }
        }

        for (int i = 0; i < n; i++) {
            if (check[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};