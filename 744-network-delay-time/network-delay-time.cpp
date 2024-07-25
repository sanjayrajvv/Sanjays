class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;

        for (int i = 1; i < n; i++) {
            for (auto edge : times) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if (dis[u] != INT_MAX && dis[u] + wt < dis[v]) {
                    dis[v] = dis[u] + wt;
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dis[i] == INT_MAX) return -1;

            maxTime = max(maxTime, dis[i]);
        }

        return maxTime;
    }
};
