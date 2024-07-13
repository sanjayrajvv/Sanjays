class Solution {
    int dfs(int node, vector<vector<int>>& graph, vector<int> &vis) {
        int change = 0;
        vis[node] = 1;

        for (auto to : graph[node]) {
            if (!vis[abs(to)]) {
                change += dfs(abs(to), graph, vis) + (to > 0);
            }
        }

        return change;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);

        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            graph[u].push_back(v);
            graph[v].push_back(-u);
        }

        vector<int> vis(n, 0);

        return dfs(0, graph, vis);
    }
};