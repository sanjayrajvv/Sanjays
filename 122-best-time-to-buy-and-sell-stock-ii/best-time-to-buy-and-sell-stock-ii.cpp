class Solution {
    int f(int index, int buy, int n, vector<int>& prices, vector<vector<int>> &dp) {
        if (index == n) return 0;

        if (dp[index][buy] != -1) return dp[index][buy];

        int profit = 0;
        if (buy) {
            int buyToday = -prices[index] + f(index + 1, !buy, n, prices, dp);
            int notBuy = f(index + 1, buy, n, prices, dp);
            
            profit = max(buyToday, notBuy);
        } else {
            int sellToday = prices[index] + f(index + 1, !buy, n, prices, dp);
            int notSell = f(index + 1, buy, n, prices, dp);

            profit = max(sellToday, notSell);
        }

        return dp[index][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return f(0, 1, n, prices, dp);
    }
};