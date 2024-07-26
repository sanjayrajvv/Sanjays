class Solution {
    int f(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if (i < 0 || i >= m || j < 0 || j >= n) return 0;
        if (i == 0 && j == 0) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        int count = 0;
        count += f(i - 1, j, m, n, dp); //up
        count += f(i, j - 1, m, n, dp); //left

        return dp[i][j] = count;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(m - 1, n - 1, m, n, dp);
    }
};