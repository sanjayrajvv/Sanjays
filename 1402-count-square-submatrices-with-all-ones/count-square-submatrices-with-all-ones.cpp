class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int r = 0; r < m; r++) dp[r][0] = matrix[r][0];
        for (int c = 0; c < n; c++) dp[0][c] = matrix[0][c];

        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                if (matrix[r][c] == 1) {
                    dp[r][c] = 1 + min({dp[r - 1][c], 
                                dp[r][c - 1], dp[r - 1][c - 1]});
                }
            }
        }

        int total = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                total += dp[r][c];
            }
        }

        return total;
    }
};