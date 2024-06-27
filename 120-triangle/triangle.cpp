class Solution {
    int f(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>> &dp) {
        if (i == n - 1) {
            return triangle[i][j];
        }

        if (i == n) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int down = INT_MAX, diag = INT_MAX;
        if (i + 1 < n) down = f(i + 1, j, n, triangle, dp);
        if (i + 1 < n && j + 1 <= i + 1) diag = f(i + 1, j + 1, n, triangle, dp);

        return dp[i][j] = triangle[i][j] + min(down, diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return f(0, 0, n, triangle, dp);
    }
};