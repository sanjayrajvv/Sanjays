class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int maxPath = 1;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                maxPath = max(maxPath, dfs(r, c, matrix, dp));
            }
        }

        return maxPath;
    }

private:
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    int dfs(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[r][c] != -1) return dp[r][c];

        int maxPath = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + delRow[i];
            int nc = c + delCol[i];

            if (bound(nr, nc, matrix) && matrix[r][c] < matrix[nr][nc]) {
                maxPath = max(maxPath, 1 + dfs(nr, nc, matrix, dp));
            }
        }

        return dp[r][c] = maxPath;
    }

    bool bound(int r, int c, vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        return r >= 0 && r < m && c >= 0 && c < n;
    }
};