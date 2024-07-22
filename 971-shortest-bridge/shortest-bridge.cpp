class Solution {
private:
    const int delRow[4] = {-1, 0, 1, 0};
    const int delCol[4] = {0, 1, 0, -1};
    
    void dfs(int r, int c, vector<vector<int>>& grid, int n, vector<vector<int>>& vis, queue<vector<int>>& q) {
        vis[r][c] = 1;
        q.push({r, c, 0});
        for (int i = 0; i < 4; ++i) {
            int nr = r + delRow[i];
            int nc = c + delCol[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] == 1) {
                dfs(nr, nc, grid, n, vis, q);
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<vector<int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        bool found = false;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1 && !vis[r][c]) {
                    dfs(r, c, grid, n, vis, q);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int r = q.front()[0];
                int c = q.front()[1];
                int flips = q.front()[2];
                q.pop();

                for (int i = 0; i < 4; ++i) {
                    int nr = r + delRow[i];
                    int nc = c + delCol[i];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                        if (grid[nr][nc] == 1 && !vis[nr][nc]) {
                            return flips;  // Found the shortest bridge
                        }
                        if (grid[nr][nc] == 0 && !vis[nr][nc]) {
                            q.push({nr, nc, flips + 1});
                            vis[nr][nc] = 1;
                        }
                    }
                }
            }
        }

        return -1; // Shouldn't reach here if there's always two islands
    }
};
