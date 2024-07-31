class Solution {
    int MOD = 1e9 + 7;
private:
    int f(int i, int target, int n, int k, vector<vector<int>> &dp) {
        if (i == n) {
            // If all dice have been used and target is achieved
            return target == 0;
        }
        if (target < 0) {
            return 0;
        }

        if (dp[i][target] != -1) {
            return dp[i][target];
        }

        int count = 0;
        // Try each possible face value from 1 to k
        for (int face = 1; face <= k; face++) {
            count = (count + f(i + 1, target - face, n, k, dp)) % MOD;
        }

        return dp[i][target] = count;
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(0, target, n, k, dp);
    }
};
