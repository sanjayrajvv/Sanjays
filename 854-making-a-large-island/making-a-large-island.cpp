#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;
    
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find(parent[node]);
    }
      
    void unite(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
private:
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    bool isValid(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        // Step 1: Create islands using Disjoint Set
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) continue;

                for (int i = 0; i < 4; i++) {
                    int nr = r + delRow[i];
                    int nc = c + delCol[i];

                    if (isValid(nr, nc, n) && grid[nr][nc] == 1) {
                        int node = r * n + c;
                        int adj = nr * n + nc;
                        ds.unite(node, adj);
                    }
                }
            }
        }

        // Step 2: Try converting each 0 to 1 and calculate the potential island size
        int maxIsland = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) continue;

                set<int> components;
                for (int i = 0; i < 4; i++) {
                    int nr = r + delRow[i];
                    int nc = c + delCol[i];

                    if (isValid(nr, nc, n) && grid[nr][nc] == 1) {
                        int adj = nr * n + nc;
                        components.insert(ds.find(adj));
                    }
                }

                int currSize = 1; // include the current cell being converted from 0 to 1
                for (int component : components) {
                    currSize += ds.size[ds.find(component)];
                }

                maxIsland = max(maxIsland, currSize);
            }
        }

        // Step 3: Consider the case where no 0 is converted to 1
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            if (grid[cellNo / n][cellNo % n] == 1) {
                maxIsland = max(maxIsland, ds.size[ds.find(cellNo)]);
            }
        }

        return maxIsland;
    }
};
