class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));
        for (int a = 0; a <= amount; a++) {
            if (a % coins[0] == 0) dp[0][a] = a / coins[0];
        }

        for (int index = 1; index < n; index++) {
            for (int a = 0; a <= amount; a++) {
                int take = 1e9;
                if (a >= coins[index]) {
                    take = 1 + dp[index][a - coins[index]];
                }
                int notTake = dp[index - 1][a];

                dp[index][a] = min(take, notTake);
            }
        }

        int count = dp[n - 1][amount];
        return (count == 1e9) ? -1 : count;
    }
};