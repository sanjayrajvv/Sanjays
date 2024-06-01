class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
        
        for (int index = n - 1; index >= 0; index--) {
            for (int transaction = 0; transaction < 2 * k; transaction++) {
                if (transaction % 2 == 0) {
                    dp[index][transaction] = max(-prices[index] + dp[index + 1][transaction + 1], 
                                                 dp[index + 1][transaction]);
                } else {
                    dp[index][transaction] = max(prices[index] + dp[index + 1][transaction + 1], 
                                                 dp[index + 1][transaction]);
                }
            }
        }

        return dp[0][0]; 
    }
};