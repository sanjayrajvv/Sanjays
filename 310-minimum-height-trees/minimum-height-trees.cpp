class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> leafNodes;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                leafNodes.push(i);
            }
        }

        int remainingNodes = n;
        while (remainingNodes > 2) {
            int leafCount = leafNodes.size();
            remainingNodes -= leafCount;

            for (int i = 0; i < leafCount; ++i) {
                int leaf = leafNodes.front();
                leafNodes.pop();

                for (const int neighbor : adj[leaf]) {
                    if (--degree[neighbor] == 1) {
                        leafNodes.push(neighbor);
                    }
                }
            }
        }

        vector<int> roots;
        while (!leafNodes.empty()) {
            roots.push_back(leafNodes.front());
            leafNodes.pop();
        }

        return roots;
    }
};