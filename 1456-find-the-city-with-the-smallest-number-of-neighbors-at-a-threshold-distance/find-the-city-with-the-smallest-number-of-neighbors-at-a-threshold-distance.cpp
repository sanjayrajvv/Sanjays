class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> A(n, vector<int>(n, INT_MAX));

        //Creating distance matrix
        for (int i = 0; i < n; i++) A[i][i] = 0;
        for (auto edge : edges) {
            int i = edge[0];
            int j = edge[1];
            int w = edge[2];

            A[i][j] = w;
            A[j][i] = w;
        }

        //Floy-Warshall Algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (A[i][k] != INT_MAX && A[k][j] != INT_MAX)
                        A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
                }
            }
        }

        int city = 0, count = INT_MAX;

        for (int i = 0; i < n; i++) {
            int current = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && A[i][j] <= distanceThreshold) {
                    current++;
                }
            }
            
            if (current < count || (count == current && i > city)) {
                count = current;
                city = i;
            }
        }

        return city;

    }
};