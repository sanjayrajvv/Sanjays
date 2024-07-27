class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int cost = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - cost);
            cost = min(cost, prices[i]);
        }

        return profit;
    }
};