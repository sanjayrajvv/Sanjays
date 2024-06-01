class Solution {
    int f(int index, int buy, int cap, int n, vector<int> &prices, vector<vector<vector<int>>> &dp) {
        if (cap == 0) return 0;
        if (index == n) return 0;

        if (dp[index][buy][cap] != -1) return dp[index][buy][cap];

        if (buy) {
            return dp[index][buy][cap] = max((-prices[index] + f(index + 1, 0, cap, n, prices, dp)), 
                        f(index + 1, 1, cap, n, prices, dp));
        } else {
            return dp[index][buy][cap] = max((prices[index] + f(index + 1, 1, cap - 1, n , prices, dp)), 
                        f(index + 1, 0, cap, n, prices, dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy) {
                        curr[buy][cap] = max((-prices[index] + after[0][cap]), 
                                    after[1][cap]);
                    } else {
                        curr[buy][cap] = max((prices[index] + after[1][cap - 1]), 
                                    after[0][cap]);
                    }
                }
            }

            after = curr;
        }

        return after[1][2];
    }
};