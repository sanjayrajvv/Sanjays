class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;

        for (int i = 1; i < n; i++) {
            for (auto edge : times) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (dis[u] != INT_MAX && dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                }
            }
        }

        int maxi = 0;
        for (int i = 1; i <= n; i++) {
            if (dis[i] == INT_MAX) {
                return -1;
            } else {
                maxi = max(maxi, dis[i]);
            }
        }

        return maxi;
    }
};