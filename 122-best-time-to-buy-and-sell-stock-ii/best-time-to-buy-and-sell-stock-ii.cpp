class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return f(0, 1, prices, dp);
    }

private:
    int f(int index, bool buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (index == prices.size()) return 0;

        if (dp[index][buy] != -1) return dp[index][buy];

        int profit = 0;
        if (buy) {
            int buyToday = -prices[index] + f(index + 1, !buy, prices, dp);
            int notBuy = f(index + 1, buy, prices, dp);

            profit = max(buyToday, notBuy);
        } else {
            int sell = prices[index] + f(index + 1, !buy, prices, dp);
            int notSell = f(index + 1, buy, prices, dp);

            profit = max(sell, notSell);
        }

        return dp[index][buy] = profit;
    }
};