class Solution {
private:
    int f(int i, int j1, int j2, int m, int n, vector<vector<int>>& grid, 
    vector<vector<vector<int>>> &dp) {
        if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) return -1;
        if (i == m - 1) {
            if (j1 == j2) {
                return grid[i][j1];
            } 
            return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int delJ1[3] = {-1, 0, 1};
        int delJ2[3] = {-1, 0, 1};

        int maxi = -1;
        for (int d1 = 0; d1 < 3; d1++) {
            for (int d2 = 0; d2 < 3; d2++) {
                int newJ1 = j1 + delJ1[d1];
                int newJ2 = j2 + delJ2[d2];
                int result = f(i + 1, newJ1, newJ2, m, n, grid, dp);

                if (j1 == j2) {
                    result += grid[i][j1];
                } else {
                    result += (grid[i][j1] + grid[i][j2]);
                }

                maxi = max(maxi, result);
            }
        }

        return dp[i][j1][j2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

        return f(0, 0, n - 1, m, n, grid, dp);
    }
};