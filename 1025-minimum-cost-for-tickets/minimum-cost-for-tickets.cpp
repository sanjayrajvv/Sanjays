class Solution {
private:
    int f(int i, vector<int>& days, vector<int>& costs, vector<int> &dp) {
        if (i < 0) return 0;

        if (dp[i] != -1) return dp[i];

        int minCost = INT_MAX;
        for (int j = 0; j < 3; j++) {
            int pass;
            if (j == 0) pass = 1;
            if (j == 1) pass = 7;
            if (j == 2) pass = 30;

            int k = i;
            while (k >= 0 && (days[i] - pass + 1) <= days[k]) k--;

            int cost = costs[j] + f (k, days, costs, dp);
            minCost = min(minCost, cost);
        }

        return dp[i] = minCost;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);

        return f(n - 1, days, costs, dp);
    }
};