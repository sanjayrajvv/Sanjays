class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, 
                                    int color) {
        int initialColor = image[sr][sc];

        dfs(sr, sc, initialColor, color, image);

        return image;
    }

private:
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    void dfs(int row, int col, int initialColor, int color, 
                                vector<vector<int>>& image) {
        image[row][col] = color;

        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (isBound(nrow, ncol, image) && image[nrow][ncol] == initialColor && 
                                                        image[nrow][ncol] != color) {
                dfs(nrow, ncol, initialColor, color, image);
            }
        }
    }

    bool isBound(int row, int col, vector<vector<int>>& image) {
        int m = image.size(), n = image[0].size();

        return row >= 0 && row < m && col >= 0 && col < n;
    }
};