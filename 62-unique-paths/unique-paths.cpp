class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else {
                    int count = 0;
                    if (i - 1 >= 0) count += dp[i - 1][j]; //up
                    if (j - 1 >= 0) count += dp[i][j - 1]; //left

                    dp[i][j] = count;
                }

            }
        }

        return dp[m - 1][n - 1];
    }
};