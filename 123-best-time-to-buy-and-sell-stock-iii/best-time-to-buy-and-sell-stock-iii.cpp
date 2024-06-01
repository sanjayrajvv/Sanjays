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

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return f(0, 1, 2, n, prices, dp);
    }
};