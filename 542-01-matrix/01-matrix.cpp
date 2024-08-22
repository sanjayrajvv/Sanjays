class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> distance(m, vector<int>(n, 0));
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (matrix[r][c] == 0) {
                    q.push({{r, c}, 0});
                    visited[r][c] = 1;
                }
            }
        }

        while (!q.empty()) {
            auto [row, col] = q.front().first;
            int steps = q.front().second;
            q.pop();
            distance[row][col] = steps;

            for (int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (isBound(nrow, ncol, m, n) && visited[nrow][ncol] == 0) {
                    visited[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps + 1});
                }
            }
        }

        return distance;
    }

private:
    int delRow[4] = {0, -1, 1, 0};
    int delCol[4] = {1, 0, 0, -1};

    bool isBound(int row, int col, int m, int n) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
};