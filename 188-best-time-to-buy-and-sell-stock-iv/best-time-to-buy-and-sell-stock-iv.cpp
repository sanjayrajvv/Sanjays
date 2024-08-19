class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int transaction = 0; transaction < 2 * k; transaction++) {
                int profit;
                if (transaction % 2 == 0) {
                    int buyToday = -prices[index] + dp[index + 1][transaction + 1];
                    int notBuy = dp[index + 1][transaction];

                    profit = max(buyToday, notBuy);
                } else {
                    int sellToday = prices[index] + dp[index + 1][transaction + 1];
                    int notSell = dp[index + 1][transaction];

                    profit = max(sellToday, notSell);
                }
                dp[index][transaction] = profit;
            }
        }

        return dp[0][0];
    }
};