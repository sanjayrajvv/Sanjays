class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 2) {
                    visited[r][c] = 2;
                    q.push({{r, c}, 0});
                } else if (grid[r][c] == 1) {
                    visited[r][c] = 1;
                }
            }
        }

        int elapseTime = 0;
        while (!q.empty()) {
            auto [row, col] = q.front().first;
            int time = q.front().second;
            q.pop();

            elapseTime = max(elapseTime, time);

            for (int i = 0; i < 4; i++) {
                int nr = row + delRow[i];
                int nc = col + delCol[i];

                if (isBound(nr, nc, m, n) && visited[nr][nc] != 2 && 
                                                grid[nr][nc] == 1) {
                    visited[nr][nc] = 2;
                    q.push({{nr, nc}, time + 1});
                }
            }
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1 && visited[r][c] != 2) {
                    return -1;
                }
            }
        }

        return elapseTime;
    }

private:
    int delRow[4] = {0, -1, 1, 0};
    int delCol[4] = {1, 0, 0, -1};

    bool isBound(int r, int c, int m, int n) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }
};