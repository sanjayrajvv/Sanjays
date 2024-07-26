class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    curr[j] = 1;
                } else if (obstacleGrid[i][j] == 1) {
                    curr[j] = 0;
                } else {
                    int count = 0;
                    if (i - 1 >= 0) {
                        count += prev[j];
                    }
                    if (j - 1 >= 0) {
                        count += curr[j - 1];
                    }
                    curr[j] = count;
                }
            }

            prev = curr;
        }

        return prev[n - 1];
     }
};