class Solution {
private:
    bool isBound(int row, int col, int n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        distance[0][0] = 0;
        queue<vector<int>> q;

        q.push({0, 0, 0});
        while (!q.empty()) {
            int dis = q.front()[0];
            int r = q.front()[1];
            int c = q.front()[2];
            q.pop();

            if (r == n - 1 && c == n - 1) {
                return dis + 1;
            }

            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, 
                          {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

            for (auto dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (isBound(nr, nc, n)) {
                    if (grid[nr][nc] == 0 && dis + 1 < distance[nr][nc]) {
                        distance[nr][nc] = dis + 1;
                        q.push({distance[nr][nc], nr, nc});
                    }
                }
            }
        }
        
        if (distance[n - 1][n - 1] == INT_MAX) return -1;
        else return distance[n - 1][n - 1] + 1;
    }
};