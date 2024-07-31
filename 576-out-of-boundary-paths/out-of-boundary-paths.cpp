class Solution {
private:
    int MOD = 1e9 + 7;

    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    int f(int r, int c, int m, int n, int moves, int maxMove,
    vector<vector<vector<int>>> &dp) {
        if (moves > maxMove) {
            return 0;
        }
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return 1;
        }

        if (dp[r][c][moves] != -1) {
            return dp[r][c][moves];
        }

        int count = 0;
        for (int i = 0; i < 4; i++) {
            int nr = r + delRow[i];
            int nc = c + delCol[i];

            count = (count + f(nr, nc, m, n, moves + 1, maxMove, dp)) % MOD;
        }

        return dp[r][c][moves] = count;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, 
        vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));

        return f(startRow, startColumn, m, n, 0, maxMove, dp);
    }
};