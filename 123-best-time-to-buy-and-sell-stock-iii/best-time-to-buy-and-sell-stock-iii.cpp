class Solution {
    int f(int index, int transaction, vector<int> &prices, vector<vector<int>> &dp) {
        if (index == prices.size() || transaction == 4) return 0;

        if (dp[index][transaction] != -1) return dp[index][transaction];

        if (transaction % 2 == 0) {
            return dp[index][transaction] = max((-prices[index] + f(index + 1, transaction + 1, prices, dp)), 
                        f(index + 1, transaction, prices, dp));
        } else {
            return dp[index][transaction] = max((prices[index] + f(index + 1, transaction + 1, prices, dp)), 
                        f(index + 1, transaction, prices, dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {

        vector<vector<int>> dp(prices.size(), vector<int>(5, -1));

        return f(0, 0, prices, dp);
    }
};