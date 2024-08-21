class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(3, vector<int>(n + 1, 0));

        for (int eggs = 0; eggs <= 2; eggs++) {
            dp[eggs][0] = 0;
            dp[eggs][1] = 1;
        }

        for (int floors = 0; floors <= n; floors++) {
            dp[1][floors] = floors;
        }

        for (int eggs = 2; eggs <= 2; eggs++) {
            for (int floors = 2; floors <= n; floors++) {
                int minMoves = INT_MAX;
                for (int x = 1; x <= floors; ++x) {
                    int worstCase = max(dp[eggs - 1][x - 1], dp[eggs][floors - x]);
                    minMoves = min(minMoves, worstCase + 1);
                }

                dp[eggs][floors] = minMoves;
            }
        }

        return dp[2][n];
    }
};