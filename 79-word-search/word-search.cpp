class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == word[0]) {
                    if (dfs(row, col, 0, word, board) == true) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

private:
    bool dfs(int row, int col, int index, string word, vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        if (row < 0 || row >= m || col < 0 || col >= n || 
            board[row][col] != word[index]) {
            return false;
        }

        if (index == word.size() - 1) {
            return true;
        }

        char temp = board[row][col];
        board[row][col] = '#';

        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (dfs(nrow, ncol, index + 1, word, board) == true) {
                return true;
            } 
        }

        board[row][col] = temp;

        return false;
    }

    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};
};