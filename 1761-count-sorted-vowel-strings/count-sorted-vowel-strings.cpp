class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(5, vector<int>(n + 1, -1));

        return f(0, n, dp);
    }

private:
    int f(int index, int n, vector<vector<int>> &dp) {
        if (n == 0) {
            return 1;
        }

        if (index >= 5) {
            return 0;
        }

        if (dp[index][n] != -1) {
            return dp[index][n];
        }

        int notTake = f(index + 1, n, dp);
        int take = f(index, n - 1, dp);

        return dp[index][n] = notTake + take;
    }
};