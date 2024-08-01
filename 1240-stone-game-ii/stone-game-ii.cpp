class Solution {
private:
    int f(int i, int m, bool turn, vector<int> &piles, vector<vector<vector<int>>>& dp) {
        int n = piles.size();
        if (i == n) {
            return 0;
        }

        if (dp[i][m][turn] != -1) {
            return dp[i][m][turn];
        }

        int maxStones = turn == true ? 0 : INT_MAX;
        int stones = 0;
        for (int j = i; j < min(i + 2 * m, n); j++) {
            stones += piles[j];
            if (turn) {
                maxStones = max(maxStones, stones + 
                f(j + 1, max(j - i + 1, m), !turn, piles, dp)); 
            } else {
                maxStones = min(maxStones, 
                f(j + 1, max(j - i + 1, m), !turn, piles, dp));
            }
        }

        return dp[i][m][turn] = maxStones;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2 * n, vector<int>(2, -1)));
        return f(0, 1, 1, piles, dp);
    }
};