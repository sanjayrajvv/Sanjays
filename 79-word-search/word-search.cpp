class Solution {
private:
    bool dfs(int r, int c, vector<vector<char>> &board, int m, int n, 
    int index, string word) {
        if (r < 0 || c < 0 || r >= m || c >= n 
        || board[r][c] != word[index]) {
            return false;
        }

        if (index == word.size() - 1) {
            return true;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nr = r + delRow[i];
            int nc = c + delCol[i];

            if (dfs(nr, nc, board, m, n, index + 1, word)) {
                return true;
            }
        }

        board[r][c] = temp;

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, board, m, n, 0, word)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};