class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> ahead1(2, 0), ahead2(2, 0);
        vector<int> curr(2, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy < 2; buy++) {
                int profit = 0;
                if (buy) {
                    int buyToday = -prices[index] + ahead1[!buy];
                    int notBuyToday = curr[buy];

                    profit = max(buyToday, notBuyToday);
                } else {
                    int sellToday = prices[index] + ahead2[!buy];
                    int notSellToday = curr[buy];

                    profit = max(sellToday, notSellToday);
                }

                curr[buy] = profit;
            }
            ahead2 = ahead1;
            ahead1 = curr;
        }

        return ahead1[1];
    }
};