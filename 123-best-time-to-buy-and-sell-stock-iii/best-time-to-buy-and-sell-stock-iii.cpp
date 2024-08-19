class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, 
                                                vector<int>(3, 0)));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int count = 2; count > 0; count--) {
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

private:
    int f(int index, bool buy, int count, 
         vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (count == 0 || index == prices.size()) return 0;

        if (dp[index][buy][count] != -1) return dp[index][buy][count];

        int profit = 0;
        if (buy) {
            int buyToday = -prices[index] + f(index + 1, !buy, count, prices, dp);
            int notBuy = f(index + 1, buy, count, prices, dp);

            profit = max(buyToday, notBuy);
        } else {
            int sellToday = prices[index] + f(index + 1, !buy, count - 1, prices, dp);
            int notSell = f(index + 1, buy, count, prices, dp);

            profit = max(sellToday, notSell);
        }

        return dp[index][buy][count] = profit;
    }
};