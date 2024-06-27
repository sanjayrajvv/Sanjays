class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int leftDiag = (j - 1 >= 0) ? dp[i - 1][j - 1] : INT_MAX;
                int up = dp[i - 1][j];
                int rightDiag = (j + 1 < n) ? dp[i - 1][j + 1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({leftDiag, up, rightDiag});
            }
        }

        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            mini = min(dp[n - 1][i], mini);
        }

        return mini;
    }
};