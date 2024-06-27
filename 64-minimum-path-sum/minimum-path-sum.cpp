class Solution {
    int f(int r, int c, int m, int n, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        if (r == m - 1 && c == n - 1) return grid[r][c];
        if (r >= m || c >= n) return INT_MAX;

        if (dp[r][c] != -1) return dp[r][c];

        int right = f(r, c + 1, m, n, grid, dp);
        int down = f(r + 1, c, m, n, grid, dp);

        return dp[r][c] = grid[r][c] + min(right, down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(0, 0, m, n, grid, dp);
    }
};