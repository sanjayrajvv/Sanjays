class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // Initialize dp array with dimensions [n + 1][4] and fill with 0.
        vector<int> ahead(5, 0), curr(5, 0);
        
        // Iterate over the days from the last to the first
        for (int index = n - 1; index >= 0; index--) {
            for (int transaction = 0; transaction < 4; transaction++) {
                if (transaction % 2 == 0) {
                    curr[transaction] = max(-prices[index] + ahead[transaction + 1], 
                                                 ahead[transaction]);
                } else {
                    curr[transaction] = max(prices[index] + ahead[transaction + 1], 
                                                ahead[transaction]);
                }
            }

            ahead = curr;
        }

        return ahead[0]; // The maximum profit starting from day 0 with 0 transactions done.
    }
};
