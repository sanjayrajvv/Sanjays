class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<vector<vector<int>>> dp(n + 1, 
        vector<vector<int>>(2 * n + 1, vector<int>(2, 0)));
        for (int i = n - 1; i >= 0; i--) {
            for (int m = 2 * n; m >= 1; m--) {
                for (int turn = 0; turn < 2; turn++) {
                    int maxStones = turn == true ? 0 : INT_MAX;
                    int stones = 0;
                    for (int j = i; j < min(i + 2 * m, n); j++) {
                        stones += piles[j];
                        if (turn) {
                            maxStones = max(maxStones, stones + 
                            dp[j + 1][max(j - i + 1, m)][!turn]); 
                        } else {
                            maxStones = min(maxStones, 
                            dp[j + 1][max(j - i + 1, m)][!turn]);
                        }
                    }

                    dp[i][m][turn] = maxStones;
                }
            }
        }

        return dp[0][1][1];
    }
};