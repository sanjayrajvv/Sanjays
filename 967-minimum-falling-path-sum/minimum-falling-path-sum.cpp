class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

        for (int j = 0; j < n; j++) dp[0][j] = matrix[0][j];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int leftDiag = j - 1 >= 0 ? dp[i - 1][j - 1] : INT_MAX;
                int up = dp[i - 1][j];
                int rightDiag = dp[i - 1][j + 1];

                dp[i][j] = matrix[i][j] + min({leftDiag, up, rightDiag});
            }
        }

        int minPathSum = INT_MAX;
        for (int j = 0; j < n; j++) {
            minPathSum = min(minPathSum, dp[n - 1][j]);
        }

        return minPathSum;
    }
};