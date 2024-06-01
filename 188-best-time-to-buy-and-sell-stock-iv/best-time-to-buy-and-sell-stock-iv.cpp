class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<int> ahead(2 * k + 1, 0), curr(2 * k + 1, 0);
        
        for (int index = n - 1; index >= 0; index--) {
            for (int transaction = 0; transaction < 2 * k; transaction++) {
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

        return ahead[0]; 
    }
};