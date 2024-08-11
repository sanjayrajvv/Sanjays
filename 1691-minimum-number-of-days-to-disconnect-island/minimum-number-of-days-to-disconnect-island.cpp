class Solution {
    const vector<vector<int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (countIslands(grid) != 1) {
            return 0; //already disconnected
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) continue;

                grid[r][c] = 0;

                if (countIslands(grid) != 1) {
                    return 1;
                }

                grid[r][c] = 1;
            }
        }

        return 2;
    }

private:
    int countIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1 && !visited[r][c]) {
                    islands++;
                    dfs(r, c, grid, visited);
                }
            }
        }

        return islands;
    }

    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        visited[r][c] = 1;

        for (auto dir : DIRECTIONS) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            if (isValid(nr, nc, grid, visited)) {
                dfs(nr, nc, grid, visited);
            }
        }
    }

    bool isValid(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();

        return r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1 && visited[r][c] == 0;
    }
};