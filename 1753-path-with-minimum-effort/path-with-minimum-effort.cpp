class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> dis(rows, vector<int>(cols, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});
        dis[0][0] = 0;

        while (!pq.empty()) {
            int effort = pq.top().first;
            auto [row, col] = pq.top().second;
            pq.pop();

            if (row == rows - 1 && col == cols - 1) {
                return effort;
            }

            for (int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (isBound(nrow, ncol, rows, cols)) {
                    int newEffort = abs(heights[row][col] - heights[nrow][ncol]);
                    int maxEffort = max(newEffort, effort);
                    
                    if (maxEffort < dis[nrow][ncol]) {
                        dis[nrow][ncol] = maxEffort;
                        pq.push({maxEffort, {nrow, ncol}});
                    }
                }
            }
        } 

        return -1;
    }

private:
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    bool isBound(int row, int col, int rows, int cols) {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }
};