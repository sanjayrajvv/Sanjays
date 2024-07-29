class Solution {
private:
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    bool isBound(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int dfs(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[r][c] != -1) return dp[r][c];

        int m = matrix.size();
        int n = matrix[0].size();

        int maxPath = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + delRow[i];
            int nc = c + delCol[i];

            if (isBound(nr, nc, m, n) && 
            matrix[nr][nc] > matrix[r][c]) {
                maxPath = max(maxPath, 1 + dfs(nr, nc, matrix, dp));
            }
        }

        return dp[r][c] = maxPath;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int maxPath = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxPath = max(maxPath, dfs(i, j, matrix, dp));
            }
        }

        return maxPath;
    }
};
