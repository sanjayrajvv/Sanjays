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

        if (obstacleGrid[0][0] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return paths(0, 0, m, n, obstacleGrid, dp);
    }
};