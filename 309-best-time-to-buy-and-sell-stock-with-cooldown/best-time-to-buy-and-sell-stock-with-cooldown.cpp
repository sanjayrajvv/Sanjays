class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy < 2; buy++) {
                int profit = 0;
                if (buy) {
                    int buyToday = -prices[index] + dp[index + 1][!buy];
                    int notBuyToday = dp[index + 1][buy];

                    profit = max(buyToday, notBuyToday);
                } else {
                    int sellToday = prices[index] + dp[index + 2][!buy];
                    int notSellToday = dp[index + 1][buy];

                    profit = max(sellToday, notSellToday);
                }

                dp[index][buy] = profit;
            }
        }

        return dp[0][1];
    }
};