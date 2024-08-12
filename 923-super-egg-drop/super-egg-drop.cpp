class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        // Base cases
        for (int eggs = 1; eggs <= k; eggs++) {
            dp[eggs][0] = 0;  // 0 floors, 0 drops needed
            dp[eggs][1] = 1;  // 1 floor, 1 drop needed
        }
        for (int floor = 1; floor <= n; floor++) {
            dp[1][floor] = floor;  // With 1 egg, we need to try all floors
        }

        // DP with binary search optimization
        for (int eggs = 2; eggs <= k; eggs++) {
            for (int floor = 2; floor <= n; floor++) {
                int low = 1, high = floor;
                while (low + 1 < high) {
                    int mid = low + (high - low) / 2;
                    int breakEgg = dp[eggs - 1][mid - 1];
                    int notBreakEgg = dp[eggs][floor - mid];

                    if (breakEgg > notBreakEgg) {
                        high = mid;
                    } else {
                        low = mid;
                    }
                }
                dp[eggs][floor] = 1 + min(max(dp[eggs - 1][low - 1], dp[eggs][floor - low]),
                                          max(dp[eggs - 1][high - 1], dp[eggs][floor - high]));
            }
        }

        return dp[k][n];
    }
};
