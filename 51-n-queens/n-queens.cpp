class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board(n, s);

        backtrack(0, n, board, ans);

        return ans;
    }

private:
    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board)) {
                board[row][col] = 'Q';
                backtrack(row + 1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(int row, int col, vector<string>& board) {
        //row and col
        int n = board[0].size();

        int r = row, c = col;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;

            r--;
            c--;
        }

        r = row, c = col;
        while (r >= 0) {
            if (board[r][c] == 'Q') return false;

            r--;
        }

        r = row, c = col;
        while (r >= 0 && c < n) {
            if (board[r][c] == 'Q') return false;

            r--;
            c++;
        }

        return true;
    }
};