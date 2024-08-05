#define ll long long 
class Solution {
private:
    int dfs(int node, vector<vector<int>>& graph, vector<int> &vis) {
        vis[node] = 1;
        int maxExplode = 1;

        for (int neighbor : graph[node]) {
            if (!vis[neighbor]) {
                maxExplode += dfs(neighbor, graph, vis);
            }
        }

        return maxExplode;
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++) {
            ll x1 = bombs[i][0];
            ll x2 = bombs[i][1];
            ll r1 = bombs[i][2];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                ll x = abs(x1 - bombs[j][0]);
                ll y = abs(x2 - bombs[j][1]);
                if (x * x + y * y <= r1 * r1) {
                    graph[i].push_back(j);
                }
            }
        }

        int maxExplode = 1;
        for (int i = 0; i < n; i++) {
            vector<int> vis(n, 0);
            maxExplode = max(maxExplode, dfs(i, graph, vis));
        }

        return maxExplode;
    }
};