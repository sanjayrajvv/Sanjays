class Solution {
private:
    bool f(int i, int j, bool turn, int alice, int bob, 
    vector<int>& piles, vector<vector<vector<int>>> &dp) {
        if (i > j) {
            return alice > bob;
        }

        if (dp[i][j][turn] != -1) {
            return dp[i][j][turn];
        }

        if (turn) {
            bool res = f(i + 1, j, !turn, alice + piles[i], bob, piles, dp) ||
            f(i, j - 1, !turn, alice + piles[j], bob, piles, dp);
            return dp[i][j][turn] = res;
        } else {
            bool res = f(i + 1, j, !turn, alice, bob + piles[i], piles, dp) || 
            f(i, j - 1, !turn, alice, bob + piles[j], piles, dp);
            return dp[i][j][turn] = res;
        }

    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));

        return f(0, n - 1, 0, 0, 0, piles, dp);
    }
};