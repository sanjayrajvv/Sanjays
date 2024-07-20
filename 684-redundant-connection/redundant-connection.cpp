class DisjointSet {
private:
    vector<int> rank;
    vector<int> parent;
public:
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v) {
            if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            } else if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            } else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DisjointSet ds(n + 1);
        
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (ds.find(u) == ds.find(v)) {
                return edge;
            }

            ds.unite(u, v);
        }

        return {};
    }
};
