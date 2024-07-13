class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        int r = entrance[0], c = entrance[1];

        queue<vector<int>> q;
        q.push(vector<int>{r, c, 0});

        vector<vector<int>> vis(m, vector<int>(n, 0));
        vis[r][c] = 1;

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            vector<int> pos = q.front();
            q.pop();

            int row = pos[0], col = pos[1], steps = pos[2];

            if ((row == 0 || row == m - 1 || col == n - 1 || col == 0) && 
            (row != r || col != c)) return steps;

            for (int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && 
                maze[nrow][ncol] == '.' && vis[nrow][ncol] == 0) { 
                    vis[nrow][ncol] = 1;
                    q.push(vector<int>{nrow, ncol, steps + 1});
                }
            }
        }

        return -1;
    }
};