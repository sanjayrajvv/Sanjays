class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        //{r, c, steps}
        queue<vector<int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> dis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front()[0];
            int c = q.front()[1];
            int steps = q.front()[2];
            q.pop();

            dis[r][c] = steps;

            for (int i = 0; i < 4; i++) {
                int nr = r + delRow[i];
                int nc = c + delCol[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc, steps + 1});
                }
            }
            
        }

        return dis;
    }
};