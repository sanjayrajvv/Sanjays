class Solution {
private:
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    bool dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[r][c] = 1;

        int m = grid.size();
        int n = grid[0].size();

        bool isClosed = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + delRow[i];
            int nc = c + delCol[i];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                isClosed = false;
            } else if (grid[nr][nc] == 0 && !vis[nr][nc]) {
                if (!dfs(nr, nc, grid, vis)) {
                    isClosed = false;
                }
            }
        }

        return isClosed;
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int closedIslands = 0;

        for (int r = 1; r < m - 1; r++) {
            for (int c = 1; c < n - 1; c++) {
                if (grid[r][c] == 0 && !vis[r][c]) {
                    if (dfs(r, c, grid, vis)) {
                        closedIslands++;
                    }
                }
            }
        }

        return closedIslands;
    }
};