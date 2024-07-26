class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = dp[i - 1][j];
                int l_diag = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
                int r_diag = (j + 1 < n) ? dp[i - 1][j + 1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({up, l_diag, r_diag});
            }
        }

        int minSum = INT_MAX;
        for (int j = 0; j < n; j++) {
            minSum = min(minSum, dp[n - 1][j]);
        }

        return minSum;
    }
};
