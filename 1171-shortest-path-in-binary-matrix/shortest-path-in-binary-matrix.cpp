class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;

        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;

        q.push({{0, 0}, 0});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto [row, col] = q.front().first;
            int dis = q.front().second;
            q.pop();

            if (row == n - 1 && col == n - 1) {
                return dis + 1;
            }

            for (auto dir : directions) {
                int nr = row + dir[0];
                int nc = col + dir[1];

                if (isBound(nr, nc, n) && vis[nr][nc] == 0 && grid[nr][nc] == 0) {
                    vis[nr][nc] = 1;
                    q.push({{nr, nc}, dis + 1});
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