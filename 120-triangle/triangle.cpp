class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < n; i++) dp[n - 1][i] = triangle[n - 1][i];

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = dp[i + 1][j];
                int right = dp[i + 1][j + 1];

                dp[i][j] = triangle[i][j] + min(down, right);
            }
        }

        return dp[0][0];
    }
};