class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUparent(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = findUparent(parent[node]);
    }

    void Union(int u, int v) {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        
        if (ulp_u == ulp_v) return;
        else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_v]++;
        }
    }
};

class Solution {
    struct Edges {
        int weight, from, to;
        bool operator<(const Edges& e) const {
            return weight < e.weight;
        }
    };

    vector<Edges> createEdges(vector<vector<int>>& points) {
        vector<Edges> edges;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int dis = abs(x1 - x2) + abs(y1 - y2);

                edges.push_back({dis, i, j});
            }
        }

        return edges;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<Edges> edges = createEdges(points);

        sort(edges.begin(), edges.end());

        DisjointSet ds(n);

        int mst = 0;
        for (auto edge : edges) {
            int w = edge.weight;
            int u = edge.from;
            int v = edge.to;

            if (ds.findUparent(u) != ds.findUparent(v)) {
                mst += w;

                ds.Union(u, v);
            }
        }

        return mst;
    }
};
//Create all the edges possible
//sort them based on thier weight
//pick each of them and connect without forming a cycle