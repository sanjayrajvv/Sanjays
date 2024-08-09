class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int magicSquareCount = 0;

        for (int r = 0; r < rows - 2; r++) {
            for (int c = 0; c < cols - 2; c++) {
                if (isMagicSquare(grid, r, c)) {
                    magicSquareCount++;
                }
            }
        }

        return magicSquareCount;
    }

private:    
    bool isMagicSquare(vector<vector<int>>& grid, int r, int c) {
        unordered_set<int> elements;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[r + i][c + j];
                if (num < 1 || num > 9 || !elements.insert(num).second) {
                    return false;
                }
            }
        }

        int sum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2]; 

        for (int i = 0; i < 3; i++) {
            if (grid[r + i][c + 0] + grid[r + i][c + 1] + grid[r + i][c + 2] != sum) {
                return false;
            }

            if (grid[r + 0][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] != sum) {
                return false;
            }
        }

        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != sum) {
            return false;
        }

        if (grid[r + 2][c] + grid[r + 1][c + 1] + grid[r][c + 2] != sum) {
            return false;
        }

        return true;
    }
};