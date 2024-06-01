class Solution {
    int f(int index, bool buy, vector<int> &prices, vector<vector<int>> &dp) {
        if (index >= prices.size()) return 0;

        if (dp[index][buy] != -1) return dp[index][buy];
        if (buy) {
            return dp[index][buy] = max((-prices[index] + f(index + 1, 0, prices, dp)), f(index + 1, 1, prices, dp));
        } else {
            return dp[index][buy] = max((prices[index] + f(index + 2, 1, prices, dp)), f(index + 1, 0, prices, dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));

        return f(0, 1, prices, dp);
    }
};