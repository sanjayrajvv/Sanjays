class Solution {
private:
    int helper(int index, int amount, vector<int>& coins, vector<vector<int>> &dp) {
        if (index == 0) {
            if (amount % coins[index] == 0) return amount / coins[index];
            else return 1e9;
        }

        if (dp[index][amount] != -1) return dp[index][amount];

        int take = 1e9;
        if (amount >= coins[index]) {
            take = 1 + helper(index, amount - coins[index], coins, dp);
        }
        int notTake = helper(index - 1, amount, coins, dp);

        return dp[index][amount] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int count = helper(n - 1, amount, coins, dp);
        if (count == 1e9) return -1;
        else return count;
    }
};