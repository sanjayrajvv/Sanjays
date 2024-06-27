class Solution {
    int paths(int r, int c, int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp) {
        if (r == m - 1 && c == n - 1) return 1;
        if (r >= m || c >= n ) return 0;

        if (dp[r][c] != -1) return dp[r][c];

        int right = 0, down = 0;
        if (r + 1 < m && obstacleGrid[r + 1][c] == 0) right = paths(r + 1, c, m, n, obstacleGrid, dp);
        if (c + 1 < n && obstacleGrid[r][c + 1] == 0) down = paths(r, c + 1, m, n, obstacleGrid, dp);

        return dp[r][c] = right + down;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (obstacleGrid[r][c] == 1) {
                    dp[r][c] = 0; 
                } else {
                    if (r > 0) dp[r][c] += dp[r-1][c];
                    if (c > 0) dp[r][c] += dp[r][c-1]; 
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};