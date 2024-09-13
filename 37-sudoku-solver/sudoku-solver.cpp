class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] != '.') continue;

                for (char c = '1'; c <= '9'; c++) {
                    if (isFeasible(row, col, c, board)) {
                        board[row][col] = c;

                        if (solve(board) == true) return true;
                        else board[row][col] = '.';
                    }
                }

                return false;
            }
        }

        return true;
    }

    bool isFeasible(int row, int col, char c, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c) return false;
            if (board[row][i] == c) return false;
        }

        int x = (row / 3) * 3;
        int y = (col / 3) * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[x + i][y + j] == c) {
                    return false;
                }
            }
        }

        return true;
    }
};