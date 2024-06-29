class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int tot = 0;

        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0];
            tot += dp[i][0];
        }

        for (int j = 1; j < n; j++) {
            dp[0][j] = matrix[0][j];
            tot += dp[0][j];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                    tot += dp[i][j];
                }
            }
        }

        return tot;
    }
};
