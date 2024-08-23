class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, 
    int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> graph(n);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<int> result(n, 0);

        for (int node = 0; node < n; node++) {
            vector<int> temp;
            int sum = 0;
            for (const auto& [neighbor, weight] : graph[node]) {
                int count = 0;
                dfs(neighbor, graph, node, weight, signalSpeed, count);
                temp.push_back(count);
                sum += count;
            }

            int totalPairs = 0;
            for (auto el : temp) {
                totalPairs = totalPairs + (sum - el) * el;
            }

            result[node] = (totalPairs) / 2;;
        }

        return result;
    }

private:
    void dfs(int node, vector<vector<pair<int, int>>>& graph, int parent, 
    int currDistance, int signalSpeed, int& count) {
        if (currDistance % signalSpeed == 0) {
            count++;
        }
        for (const auto& [neighbor, weight] : graph[node]) {
            if (neighbor != parent) {
                int newDistance = currDistance + weight;
                dfs(neighbor, graph, node, newDistance, signalSpeed, count);
            }
        }
    }
};