class Solution {
private:
    const int delRow[4] = {-1, 0, 1, 0};
    const int delCol[4] = {0, 1, 0, -1};

    int dfsBacktrack(int r, int c, int m, int n, vector<vector<int>>& grid) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return 0;
        }
        int maxGold = 0;

        int originalVal = grid[r][c];
        grid[r][c] = 0;

        for (int i = 0; i < 4; i++) {
            int nr = r + delRow[i];
            int nc = c + delCol[i];

            maxGold = max(maxGold, dfsBacktrack(nr, nc, m, n, grid)); 
        }

        grid[r][c] = originalVal;
        return maxGold + originalVal;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxGold = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                maxGold = max(maxGold, dfsBacktrack(r, c, m, n, grid));
            }
        }

        return maxGold;
    }
};