class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    int count = 0;
                    if (i - 1 >= 0) {
                        count += dp[i - 1][j];
                    }
                    if (j - 1 >= 0) {
                        count += dp[i][j - 1];
                    }
                    dp[i][j] = count;
                }
            }
        }

        return dp[m - 1][n - 1];
     }
};