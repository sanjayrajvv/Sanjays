class Solution {
private:
    bool isValid(int r, int c, int m, int n) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }

    void dfs(int r, int c, vector<vector<int>> &vis, int prevHeight, 
    vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vis[r][c] = 1;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + delRow[i];
            int nc = c + delCol[i];

            if (isValid(nr, nc, m, n) && !vis[nr][nc] && prevHeight <= heights[nr][nc]) {
                dfs(nr, nc, vis, heights[nr][nc], heights);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> visPacific(m, vector<int>(n, 0));
        vector<vector<int>> visAtlantic(m, vector<int>(n, 0));

        for (int r = 0; r < m; r++) {
            dfs(r, 0, visPacific, heights[r][0], heights);
            dfs(r, n - 1, visAtlantic, heights[r][n - 1], heights);
        }

        for (int c = 0; c < n; c++) {
            dfs(0, c, visPacific, heights[0][c], heights);
            dfs(m - 1, c, visAtlantic, heights[m - 1][c], heights);
        }

        vector<vector<int>> coordinates;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (visPacific[r][c] && visAtlantic[r][c]) {
                    coordinates.push_back({r, c});
                }
            }
        }

        return coordinates; 
    }
};