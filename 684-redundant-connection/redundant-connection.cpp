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
        while (u != parent[u]) {
            u = parent[u];
        }

        return u;
    }

    void unionBySize(int u, int v) {
        int up = find(u);
        int vp = find(v);

        if (up != vp) {
            if (size[up] < size[vp]) {
                parent[up] = vp;
                size[vp] += size[up];
            } else {
                parent[vp] = up;
                size[up] += size[vp];
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
            ds.unionBySize(u, v);
        }

        return {};
    }
};