class Solution {
    int f(int index, int buy, int count, int n, vector<int>& prices, vector<vector<vector<int>>> &dp) {
        if (count == 0) return 0;
        if (index == n) return 0;

        if (dp[index][buy][count] != -1) return dp[index][buy][count];

        int profit = 0;
        if (buy) {
            int buyToday = -prices[index] + f(index + 1, !buy, count, n, prices, dp);
            int notBuy = f(index + 1, buy, count, n, prices, dp);
            
            profit = max(buyToday, notBuy);
        } else {
            int sellToday = prices[index] + f(index + 1, !buy, count - 1, n, prices, dp);
            int notSell = f(index + 1, buy, count, n, prices, dp);

            profit = max(sellToday, notSell);
        }

        return dp[index][buy][count] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return f(0, 1, 2, n, prices, dp);
    }
};