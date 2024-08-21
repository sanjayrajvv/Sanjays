class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(3, vector<int>(n + 1, -1));

        return f(2, n, dp);
    }

private:
    int f(int eggs, int floors, vector<vector<int>>& dp) {
        if (floors == 0 || floors == 1) {
            return floors;
        }

        if (eggs == 1) {
            return floors;
        }

        if (dp[eggs][floors] != -1) return dp[eggs][floors];

        int minMoves = INT_MAX;
        for (int x = 1; x <= floors; ++x) {
            int worstCase = max(f(eggs - 1, x - 1, dp), 
                                f(eggs, floors - x, dp));
            minMoves = min(minMoves, worstCase + 1);
        }

        dp[eggs][floors] = minMoves;
        return dp[eggs][floors];
    }
};