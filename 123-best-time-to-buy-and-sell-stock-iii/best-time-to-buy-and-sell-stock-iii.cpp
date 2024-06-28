class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> next(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int count = 1; count < 3; count++) {
                    int profit = 0;
                    if (buy) {
                        int buyToday = -prices[index] + next[!buy][count];
                        int notBuy = next[buy][count];
                        
                        profit = max(buyToday, notBuy);
                    } else {
                        int sellToday = prices[index] + next[!buy][count - 1];
                        int notSell = next[buy][count];

                        profit = max(sellToday, notSell);
                    }

                    curr[buy][count] = profit;
                }
                next = curr;
            }
        }

        return next[1][2];
    }
};