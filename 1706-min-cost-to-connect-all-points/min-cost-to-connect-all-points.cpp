class Solution {
private:
    vector<vector<pair<int, int>>> createGraph(int n, vector<vector<int>>& points) {
        vector<vector<pair<int, int>>> graph(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int dis = abs(x1 - x2) + abs(y1 - y2);

                graph[i].push_back({dis, j});
                graph[j].push_back({dis, i});
            }
        }

        return graph;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> graph = createGraph(n, points);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(n, 0);

        int cost = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (vis[node]) continue;

            vis[node] = 1;
            cost += dis;

            for (auto j : graph[node]) {
                int adj = j.second;
                int wt = j.first;

                if (!vis[adj]) {
                    pq.push({wt, adj});
                }
            }
        }

        return cost;
    }
};