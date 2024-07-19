class Solution {
private:
    bool isValid(int r, int c, int rows, int cols) {
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), columns = heights[0].size();
        vector<vector<int>> dis(rows, vector<int>(columns, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0, 0, 0});
        dis[0][0] = 0;
        while (!pq.empty()) {
            int effort = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();

            if (row == rows - 1 && col == columns - 1) {
                return effort;
            }

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (isValid(nrow, ncol, rows, columns)) {
                    int newEffort = max(abs(heights[nrow][ncol] - heights[row][col]), effort);
                    if (newEffort < dis[nrow][ncol]) {
                        dis[nrow][ncol] = newEffort;
                        pq.push({dis[nrow][ncol], nrow, ncol});
                    }
                }
            }
        }

        return -1;
    }
};