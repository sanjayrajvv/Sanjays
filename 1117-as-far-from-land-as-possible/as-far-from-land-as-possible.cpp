class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q; //{r, c}

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    dis[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, -1, 0, 1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + delRow[i];
                int nc = c + delCol[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    if (grid[nr][nc] == 0 && dis[nr][nc] > 1 + dis[r][c]) {
                        dis[nr][nc] = 1 + dis[r][c];
                        q.push({nr, nc});
                    }
                }
            }
        }

        int maxDistance = -1;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    maxDistance = max(maxDistance, dis[r][c]);
                }
            }
        }

        return (maxDistance == INT_MAX) ? -1 : maxDistance;
    }
};