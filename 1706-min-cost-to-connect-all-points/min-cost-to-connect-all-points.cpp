class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<pair<int, int>>> graph = createGraph(n, points);
        vector<int> vis(n, 0);

        priority_queue<pair<int, int>, vector<pair<int, int>>, 
                                    greater<pair<int, int>>> pq;

        pq.push({0, 0});

        int minimumCost = 0;
        while (!pq.empty()) {
            auto [weight, node] = pq.top();
            pq.pop();

            if (vis[node]) {
                continue;
            }
            
            vis[node] = 1;
            minimumCost += weight;

            for (auto [neighbor, edW] : graph[node]) {
                if (vis[neighbor] == 0) {
                    pq.push({edW, neighbor});
                }
            }
        }

        return minimumCost;

    }

private:
    vector<vector<pair<int, int>>> createGraph(int n, vector<vector<int>>& points) {
        vector<vector<pair<int, int>>> graph(n);

        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int x1 = points[i][0]; int y1 = points[i][1];
                int x2 = points[j][0]; int y2 = points[j][1];

                int dis = abs(x1 - x2) + abs(y1 - y2);

                graph[i].push_back({j, dis});
                graph[j].push_back({i, dis});
            }
        }

        return graph;
    }
};