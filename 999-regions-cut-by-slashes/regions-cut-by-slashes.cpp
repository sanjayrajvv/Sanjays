class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> expandedGrid(3 * n, vector<int>(3 * n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int baseRow = i * 3;
                int baseCol = j * 3;

                if (grid[i][j] == '\\') {
                    expandedGrid[baseRow][baseCol] = 1;
                    expandedGrid[baseRow + 1][baseCol + 1] = 1;
                    expandedGrid[baseRow + 2][baseCol + 2] = 1;
                } else if (grid[i][j] == '/') {
                    expandedGrid[baseRow + 2][baseCol] = 1;
                    expandedGrid[baseRow + 1][baseCol + 1] = 1;
                    expandedGrid[baseRow][baseCol + 2] = 1;
                }
            }
        }

        int rows = n * 3;
        int cols = n * 3;

        vector<vector<int>> vis(rows, vector<int>(rows, 0));
        int regions = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (!vis[r][c] && expandedGrid[r][c] == 0) {
                    regions++;
                    dfs(r, c, rows, cols, expandedGrid, vis);
                }
            }
        }

        return regions;
    }

private:
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    void dfs(int r, int c, int rows, int cols, 
            vector<vector<int>>& grid, vector<vector<int>>& vis) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || vis[r][c] || grid[r][c] == 1) {
            return;
        }

        vis[r][c] = 1;

        for (int i = 0; i < 4; i++) {
            int nr = r + delRow[i];
            int nc = c + delCol[i];

            dfs(nr, nc, rows, cols, grid, vis);
        }
    }
};