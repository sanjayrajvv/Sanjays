class DisjointSet {
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int u) {
        if (u == parent[u]) {
            return u;
        }

        return parent[u] = find(parent[u]);
    }

    void unionBySize(int u, int v) {
        int up = find(u);
        int vp = find(v);

        if (up == vp) {
            return;
        }else if (size[up] < size[vp]) {
            parent[up] = vp;
            size[vp] += size[up];
        } else {
            parent[vp] = up;
            size[up] += size[vp];
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<pair<int, int>>> graph = createGraph(n, points);

        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < n; i++) {
            for (auto [adjN, weight] : graph[i]) {
                edges.push_back({weight, {i, adjN}});
            }
        }

        sort(edges.begin(), edges.end());
        DisjointSet ds(n);
        int minimumCost = 0;

        for (auto edge : edges) {
            int weight = edge.first;
            auto [u, v] = edge.second;

            if (ds.find(u) != ds.find(v)) {
                minimumCost += weight;

                ds.unionBySize(u, v);
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