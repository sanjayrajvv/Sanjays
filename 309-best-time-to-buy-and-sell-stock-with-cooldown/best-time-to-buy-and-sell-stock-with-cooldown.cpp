class Solution {
private:
    int f(int index, bool buy, vector<int> &prices, vector<vector<int>> &dp) {
        if (index >= prices.size()) return 0;

        if (dp[index][buy] != -1) return dp[index][buy];

        int profit = 0;
        if (buy) {
            int buyToday = -prices[index] + f(index + 1, !buy, prices, dp);
            int notBuyToday = f(index + 1, buy, prices, dp);

            profit = max(buyToday, notBuyToday);
        } else {
            int sellToday = prices[index] + f(index + 2, !buy, prices, dp);
            int notSellToday = f(index + 1, buy, prices, dp);

            profit = max(sellToday, notSellToday);
        }

        return dp[index][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return f(0, 1, prices, dp);
    }
};