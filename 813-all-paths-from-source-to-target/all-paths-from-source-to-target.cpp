class Solution {
private:
    void dfsBacktrack(int node, int n, vector<vector<int>>& graph, 
    vector<int>& vis, vector<int>& ds, vector<vector<int>>& paths) {
        vis[node] = 1;
        ds.push_back(node);

        if (node == n - 1) {
            paths.push_back(ds);
            return;
        } 

        for (int nei : graph[node]) {
            if (!vis[nei]) {
                dfsBacktrack(nei, n, graph, vis, ds, paths);
                vis[nei] = 0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> paths;
        vector<int> ds;
        vector<int> vis(n, 0);

        dfsBacktrack(0, n, graph, vis, ds, paths);

        return paths;
    }
};