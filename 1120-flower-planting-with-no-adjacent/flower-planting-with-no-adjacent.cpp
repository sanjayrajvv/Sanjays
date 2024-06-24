//Try out all colors on nodes using recursion
//Create adjacency matrix
//try planting each colors and if not possible then backtrack

class Solution {
    bool possible(int node, int col, vector<vector<int>> &adj, vector<int> &color) {
        for (auto it : adj[node]) {
            if (color[it] == col) return false;
        }

        return true;
    }
    vector<vector<int>> createAjacencyList(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < paths.size(); i++) {
            int u = paths[i][0];
            int v = paths[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }
    bool graphColor(int node, int n, vector<vector<int>> &adj, vector<int> &color, vector<int> &ans) {
        if (node > n) {
            return true;
        }

        for (int col = 1; col <= 4; col++) {
            if (possible(node, col, adj, color)) {
                color[node] = col;
                ans.push_back(col);

                if (graphColor(node + 1, n, adj, color, ans) == true) {
                    return true;
                }

                ans.pop_back();
                color[node] = 0;
            }
        }

        return false;
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj = createAjacencyList(n, paths);

        vector<int> color(n + 1, 0);

        vector<int> ans;

        graphColor(1, n, adj, color, ans);

        return ans;
    }
};