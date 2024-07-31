class Solution {
    int MOD = 1e9 + 7;
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[n][0] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int currTarget = 0; currTarget <= target; currTarget++) {
                int count = 0;
                // Try each possible face value from 1 to k
                for (int face = 1; face <= k; face++) {
                    if (currTarget >= face) {
                        count = (count + dp[i + 1][currTarget - face]) % MOD;
                    }
                }

                dp[i][currTarget] = count;
            }
        }

        return dp[0][target];
    }
};
