class Solution {
private:
    int f(int index, bool buy, int count, vector<int> &prices, 
    vector<vector<vector<int>>> &dp) {
        if (index == prices.size() || count == 0) return 0;

        if (dp[index][buy][count] != -1) return dp[index][buy][count];

        int profit = 0;
        if (buy) {
            int buyToday = -prices[index] + f(index + 1, !buy, count, prices, dp);
            int notBuyToday = f(index + 1, buy, count, prices, dp);

            profit = max(buyToday, notBuyToday);
        } else {
            int sellToday = prices[index] + f(index + 1, !buy, count - 1, prices, dp);
            int notSellToday = f(index + 1, buy, count, prices, dp);

            profit = max(sellToday, notSellToday);
        }

        return dp[index][buy][count] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return f(0, 1, 2, prices, dp);
    }
};