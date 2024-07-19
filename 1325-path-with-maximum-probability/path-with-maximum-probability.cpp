class Solution {
private:
    vector<vector<pair<double, int>>> createGraph(int n, vector<vector<int>>& edges,
    vector<double>& succProb) {
        vector<vector<pair<double, int>>> graph(n);

        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            double prob = succProb[i];

            graph[a].push_back({prob, b});
            graph[b].push_back({prob, a});
        }

        return graph;
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, 
    vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double, int>>> graph = createGraph(n, edges, succProb);
        vector<double> probability(n, 0.0);
        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
        
        probability[start_node] = 1;
        pq.push({1.0, start_node});
        while (!pq.empty()) {
            auto[prob, node] = pq.top(); 
            pq.pop();

            for (auto neighbor : graph[node]) {
                auto[p, adj] = neighbor;

                if (prob * p > probability[adj]) {
                    probability[adj] = prob * p;
                    pq.push({probability[adj], adj});
                }
            }
        }

        return probability[end_node];
    }
};