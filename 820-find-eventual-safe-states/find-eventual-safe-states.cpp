class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> check(n, 1);

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs(i, graph, vis, pathVis, check);
            }
        }

        vector<int> safeNodes;
        for (int i = 0; i < n; i++) {
            if (check[i] == 1) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }

private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, 
                vector<int>& pathVis, vector<int>& check) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (int nei : graph[node]) {
            if (vis[nei] == 0) {
                if (dfs(nei, graph, vis, pathVis, check) == true) {
                    check[node] = 0;
                    return true;
                }
            } else if (pathVis[nei]) {
                check[node] = 0;
                return true;
            }
        }

        pathVis[node] = 0;

        return false;
    }
};