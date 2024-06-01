class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // Initialize dp array with dimensions [n + 1][4] and fill with 0.
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));
        
        // Iterate over the days from the last to the first
        for (int index = n - 1; index >= 0; index--) {
            for (int transaction = 0; transaction < 4; transaction++) {
                if (transaction % 2 == 0) {
                    dp[index][transaction] = max(-prices[index] + dp[index + 1][transaction + 1], 
                                                 dp[index + 1][transaction]);
                } else {
                    dp[index][transaction] = max(prices[index] + dp[index + 1][transaction + 1], 
                                                 dp[index + 1][transaction]);
                }
            }
        }

        return dp[0][0]; // The maximum profit starting from day 0 with 0 transactions done.
    }
};
