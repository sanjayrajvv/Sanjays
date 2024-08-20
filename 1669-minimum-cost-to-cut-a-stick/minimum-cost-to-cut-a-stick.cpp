class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size() - 2;

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));

        return f(1, m, cuts, dp);
    }

private:
    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int miniCost = INT_MAX;
        for (int index = i; index <= j; index++) {
            int cost = (cuts[j + 1] - cuts[i - 1]) + 
                    f(i, index - 1, cuts, dp) +
                    f(index + 1, j, cuts, dp);
            miniCost = min(miniCost, cost);
        }

        return dp[i][j] = miniCost;
    }
};