class Solution {
private:
    const int delRow[4] = {-1, 0, 1, 0};
    const int delCol[4] = {0, 1, 0, -1};

    bool isValid(int r, int c, int m , int n) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }

    bool dfs(int r, int c, vector<vector<int>>& grid1, vector<vector<int>>& grid2, 
             int m, int n, vector<vector<int>> &vis) {
        vis[r][c] = 1;
        bool isSubIsland = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + delRow[i];
            int nc = c + delCol[i];

            if (isValid(nr, nc, m, n) && grid2[nr][nc] && !vis[nr][nc]) {
                if (!dfs(nr, nc, grid1, grid2, m, n, vis)) {
                    isSubIsland = false;
                }
            }
        }

        // If the current cell in grid2 is land but not in grid1, it cannot be a sub-island.
        if (!grid1[r][c]) {
            isSubIsland = false;
        }

        return isSubIsland;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        int subIslands = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid2[r][c] && !vis[r][c]) {
                    if (dfs(r, c, grid1, grid2, m, n, vis)) {
                        subIslands++;
                    }
                }
            }
        }

        return subIslands;
    }
};
