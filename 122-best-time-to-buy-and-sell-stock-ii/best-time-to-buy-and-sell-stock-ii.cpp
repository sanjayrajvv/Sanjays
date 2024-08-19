class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy < 2; buy++) {
                int profit = 0;

                if (buy) {
                    int buyToday = -prices[index] + dp[index + 1][!buy];
                    int notBuy = dp[index + 1][buy];

                    profit = max(buyToday, notBuy);
                } else {
                    int sell = prices[index] + dp[index + 1][!buy];
                    int notSell = dp[index + 1][buy];

                    profit = max(sell, notSell);
                }

                dp[index][buy] = profit;
            }
        }

        return dp[0][1];
    }
};