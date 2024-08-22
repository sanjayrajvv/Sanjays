class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<int>> visPacific(m, vector<int>(n, 0));
        vector<vector<int>> visAtlantic(m, vector<int>(n, 0));

        for (int r = 0; r < m; r++) {
            dfs(r, 0, heights, visPacific);
            dfs(r, n - 1, heights, visAtlantic);
        }

        for (int c = 0; c < n; c++) {
            dfs(0, c, heights, visPacific);
            dfs(m - 1, c, heights, visAtlantic);
        }

        vector<vector<int>> result;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (visPacific[r][c] && visAtlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }

private:
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    void dfs(int row, int col, vector<vector<int>>& heights, 
                                  vector<vector<int>>& vis) {
        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (isBound(nrow, ncol, heights) && vis[nrow][ncol] == 0 && 
                heights[row][col] <= heights[nrow][ncol]) {
                dfs(nrow, ncol, heights, vis);
            }
        }
    }

    bool isBound(int row, int col, vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        return row >= 0 && row < m && col >= 0 && col < n;
    }
};