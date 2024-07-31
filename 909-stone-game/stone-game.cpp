class Solution {
private:
    int f(int i, int j, vector<int>& piles, vector<vector<int>>& dp) {
        if (i > j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Calculate the score difference if the current player picks i or j
        int pickLeft = piles[i] - f(i + 1, j, piles, dp);
        int pickRight = piles[j] - f(i, j - 1, piles, dp);

        // Return the best option for the current player
        return dp[i][j] = max(pickLeft, pickRight);
    }

public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n - 1, piles, dp) > 0;
    }
};
