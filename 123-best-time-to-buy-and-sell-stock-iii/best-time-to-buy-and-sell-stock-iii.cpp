class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int count = 1; count < 3; count++) {
                    int profit = 0;
                    if (buy) {
                        int buyToday = -prices[index] + dp[index + 1][!buy][count];
                        int notBuy = dp[index + 1][buy][count];
                        
                        profit = max(buyToday, notBuy);
                    } else {
                        int sellToday = prices[index] + dp[index + 1][!buy][count - 1];
                        int notSell = dp[index + 1][buy][count];

                        profit = max(sellToday, notSell);
                    }

                    dp[index][buy][count] = profit;
                }
            }
        }

        return dp[0][1][2];
    }
};