class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n, INT_MAX));
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            mat[u][v] = w;
            mat[v][u] = w;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][k] != INT_MAX && mat[k][j] != INT_MAX) {
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
        }

        int city = 0;
        int cityCount = INT_MAX;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if ( i != j && mat[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count < cityCount || (count == cityCount && i > city)) {
                city = i;
                cityCount = count;
            }
        }

        return city;
    }
};