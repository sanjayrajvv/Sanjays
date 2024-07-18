class Solution {
private:
    vector<vector<int>> createGraph(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);  // Initialize graph with n nodes
        
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];

            graph[v].push_back(u);
        }

        return graph;
    }
    
    void dfs(int i, const vector<vector<int>> &graph, vector<int> &vis, vector<int> &ans) {
        vis[i] = 1;

        for (auto j : graph[i]) {
            if (!vis[j]) {
                ans.push_back(j);
                dfs(j, graph, vis, ans);
            }
        }
    }
    
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph = createGraph(n, edges);
        vector<vector<int>> ancestors(n);

        for (int i = 0; i < n; i++) {
            vector<int> vis(n, 0);
            vector<int> ans;
            dfs(i, graph, vis, ans);
            sort(ans.begin(), ans.end());  // Sort the ancestors list
            ancestors[i] = ans;
        }

        return ancestors;
    }
};
