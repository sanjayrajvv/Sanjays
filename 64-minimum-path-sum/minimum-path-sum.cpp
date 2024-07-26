class Solution {
private:
    int f(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        if (i < 0 || i >= m || j < 0 || j >= n) return INT_MAX;
        if (i == 0 && j == 0) return grid[i][j];

        if (dp[i][j] != -1) return dp[i][j];

        int up = 0, left = 0;
        up = f(i - 1, j, m, n, grid, dp);
        left = f(i, j - 1, m, n, grid, dp);

        return dp[i][j] = grid[i][j] + min(up, left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(m - 1, n - 1, m, n, grid, dp);
    }
};