class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, graph, color) == false) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    bool dfs(int node, int col, vector<vector<int>>& graph, vector<int>& color) {
        color[node] = col;

        for (int nei : graph[node]) {
            if (color[nei] == -1) {
                if (dfs(nei, !col, graph, color) == false) {
                    return false;
                }
            } else if (color[nei] == col) {
                return false;
            }
        }

        return true;
    }
};