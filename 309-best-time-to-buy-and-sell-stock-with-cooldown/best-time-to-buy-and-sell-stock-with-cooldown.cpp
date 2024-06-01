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
        vector<int> front1(2, 0), front2(2, 0), curr(2, 0);

        for (int index = prices.size() - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    curr[buy] = max((-prices[index] + front1[0]), front1[1]);
                } else {
                    curr[buy] = max((prices[index] + front2[1]), front1[0]);
                }
            }

            front2 = front1;
            front1 = curr;
        }

        return front1[1];
    }
};