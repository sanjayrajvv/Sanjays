class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> next(2, 0);
        vector<int> curr(2, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy < 2; buy++) {
                int profit = 0;
                if (buy) {
                    int buyToday = -prices[index] + next[!buy];
                    int notBuy = next[buy];
                    
                    profit = max(buyToday, notBuy);
                } else {
                    int sellToday = prices[index] + next[!buy];
                    int notSell = next[buy];

                    profit = max(sellToday, notSell);
                }

                curr[buy] = profit;
            }
            next = curr;
        }

        return next[1];
    }
};