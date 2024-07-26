class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    curr[j] = grid[i][j];
                } else {
                    int up = INT_MAX;
                    if (i - 1 >= 0) up = prev[j];
                    int left = INT_MAX;
                    if (j - 1 >= 0) left = curr[j - 1];

                    curr[j] = grid[i][j] + min(up, left);
                }
            }
            prev = curr;
        }

        return prev[n - 1];
    }
};