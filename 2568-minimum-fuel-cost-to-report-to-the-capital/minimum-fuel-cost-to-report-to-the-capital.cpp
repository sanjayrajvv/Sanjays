class Solution {
private:
    long long fuel = 0;

    int dfs(int node, vector<vector<int>>& graph, vector<int> &vis, int seats) {
        vis[node] = 1;
        int people = 1;

        for (int neighbor : graph[node]) {
            if (!vis[neighbor]) {
                people += dfs(neighbor, graph, vis, seats);
            }
        }

        if (node != 0) {
            fuel += (people + seats - 1) / seats; //same as ceil(peopel / seats) 
        }

        return people;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < n; i++) {
            int u = roads[i][0];
            int v = roads[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> vis(n + 1, 0);
        dfs(0, graph, vis, seats);

        return fuel;
    }
};