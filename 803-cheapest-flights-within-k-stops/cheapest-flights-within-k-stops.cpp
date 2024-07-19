class Solution {
private:
    vector<vector<vector<int>>> createGraph(int n, vector<vector<int>>& flights) {
        vector<vector<vector<int>>> graph(n);

        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];

            graph[u].push_back({v, cost});
        }

        return graph;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> graph = createGraph(n, flights);
        vector<int> distance(n, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0, src, 0});
        distance[src] = 0;
        while (!pq.empty()) {
            int stops = pq.top()[0];
            int node = pq.top()[1];
            int cost = pq.top()[2];
            pq.pop();

            if (stops > k) continue;
            for (auto j : graph[node]) {
                int neighbor = j[0];
                int currCost = j[1];

                if (cost + currCost < distance[neighbor]) {
                    distance[neighbor] = cost + currCost;
                    pq.push({stops + 1, neighbor, distance[neighbor]});
                }
            }
        }

        if (distance[dst] == INT_MAX) return -1;
        else return distance[dst];
    }
};