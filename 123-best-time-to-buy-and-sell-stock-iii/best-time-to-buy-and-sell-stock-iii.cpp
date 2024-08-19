class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return f(0, 1, 2, prices, dp);
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