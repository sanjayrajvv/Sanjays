class Solution {
bool isValid(int r, int c, vector<vector<char>>& board) {
    char num = board[r][c];

    // Check row
    for (int i = 0; i < 9; ++i) {
        if (i != c && board[r][i] == num) {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < 9; ++i) {
        if (i != r && board[i][c] == num) {
            return false;
        }
    }

    int boxRow = (r / 3) * 3;
    int boxCol = (c / 3) * 3;
    for (int i = boxRow; i < boxRow + 3; ++i) {
        for (int j = boxCol; j < boxCol + 3; ++j) {
            if (i != r && j != c && board[i][j] == num) {
                return false;
            }
        }
    }

    return true; 
}


public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (isValid(i, j, board) == false) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};