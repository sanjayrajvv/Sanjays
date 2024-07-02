class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        //0->2->1
        //1->3->0

        int m = board.size(), n = board[0].size();

        vector<pair<int, int>> adj = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, 
                                      {1, 1}, {1, 0}, {1, -1}, {0, -1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
        
                int count = 0;
                for (auto ad : adj) {
                    int ni = i + ad.first;
                    int nj = j + ad.second;

                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        if (board[ni][nj] == 1 || board[ni][nj] == 3) count++;
                    }
                }

                if (board[i][j] == 1 || board[i][j] == 3) {
                    if (count < 2 || count > 3) {
                        board[i][j] = 3;
                    }
                } else {
                    if (count == 3) {
                        board[i][j] = 2;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 3) board[i][j] = 0;
                else if (board[i][j] == 2) board[i][j] = 1;
            }
        }
    }
};