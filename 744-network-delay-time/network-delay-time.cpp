class Solution {
private:
    vector<vector<pair<int, int>>> createGraph(int n, vector<vector<int>>& times) {
        vector<vector<pair<int, int>>> graph(n + 1);

        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            graph[u].push_back({v, wt});
        }

        return graph;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph = createGraph(n, times);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;

        pq.push({0, k});
        while (!pq.empty()) {
            auto [curDist, node] = pq.top();
            pq.pop();

            if (curDist > dis[node]) continue;

            for (auto [v, wt] : graph[node]) {
                if (dis[node] + wt < dis[v]) {
                    dis[v] = dis[node] + wt;
                    pq.push({dis[v], v});
                }
            }
        }

        int maxi = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (dis[i] == INT_MAX) {
                return -1;
            }

            maxi = max(maxi, dis[i]);
        }

        return maxi;
    }
};
