class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;

        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        q.push({0, 0});
        dis[0][0] = 0;

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            if (row == n - 1 && col == n - 1) {
                return dis[n - 1][n - 1] + 1;
            }

            for (auto dir : directions) {
                int nr = row + dir[0];
                int nc = col + dir[1];

                if (isBound(nr, nc, n) && grid[nr][nc] == 0 && 
                dis[nr][nc] > 1 + dis[row][col]) {
                    dis[nr][nc] = 1 + dis[row][col];
                    q.push({nr, nc});
                }
            }
        }

        return -1;
    }

private:
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}, 
    {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

    bool isBound(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }
};