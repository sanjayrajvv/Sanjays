class Solution {
    int f(int index, int buy, int n, int fee, vector<int> &prices, vector<vector<int>> &dp) {
        if (index == n) return 0;

        if (dp[index][buy] != -1) return dp[index][buy];

        int profit = 0;
        if (buy) {
            profit = max(-prices[index] + f(index + 1, 0, n, fee, prices, dp), 
                            f(index + 1, 1, n, fee, prices, dp));
        } else {
            profit = max((prices[index] - fee + f(index + 1, 1, n, fee, prices, dp)), f(index + 1, 0, n, fee, prices, dp));
        }

        return dp[index][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    dp[index][buy] = max(-prices[index] + dp[index + 1][0], 
                                    dp[index + 1][1]);
                } else {
                    dp[index][buy] = max((prices[index] - fee + dp[index + 1][1]), 
                                dp[index + 1][0]);
                }
            }
        }

        return dp[0][1];
    }
};