class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        if (grid[0][0] == 1) health--; 
        if (health <= 0) return false; 

        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<int>>> 
        dp(m, vector<vector<int>>(n, vector<int>(health + 1, -1)));

        vector<vector<int>> vis(m, vector<int>(n, 0));

        vis[0][0] = 1;
        return f(0, 0, grid, health, vis, dp);
    }

private:
    bool f(int r, int c, vector<vector<int>>& grid, int health, 
            vector<vector<int>>& vis, vector<vector<vector<int>>> &dp) {
        int m = grid.size(), n = grid[0].size();

        if (r == m - 1 && c == n - 1) return true;

        //if (r < 0 || c < 0 || r >= m || c >= n || health == 0) return false;

        if (dp[r][c][health] != -1) return dp[r][c][health];

        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = r + delRow[i];
            int nc = c + delCol[i];

            if (isValid(nr, nc, grid) && vis[nr][nc] == 0) {
                int newHealth = health;

                if (grid[nr][nc] == 1) {
                    newHealth -= 1;
                }

                if (newHealth > 0) {
                    vis[nr][nc] = 1;

                    if (f(nr, nc, grid, newHealth, vis, dp) == true) {
                        return dp[nr][nc][health] = true;
                    }

                    vis[nr][nc] = 0;
                }
            }
        }

        return dp[r][c][health] = false;

    }

    bool isValid(int r, int c, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        return r >= 0 && c >= 0 && r < m && c < n;
    }
};