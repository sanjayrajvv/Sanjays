class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == ch) return false;
            if (board[row][i] == ch) return false;
        }

        int x = (row / 3) * 3;
        int y = (col / 3) * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[x + i][y + j] == ch) return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board) == true) return true;
                            board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};