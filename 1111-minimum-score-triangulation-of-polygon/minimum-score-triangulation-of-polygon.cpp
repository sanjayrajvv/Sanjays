class Solution {
private:
    int f(int i, int j, vector<int> &values, vector<vector<int>> &dp) {
        if (j - i < 2) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int score = values[i] * values[k] * values[j] +
                        f(i, k, values, dp) +
                        f(k, j, values, dp);
            mini = min(mini, score);
        }

        return dp[i][j] = mini;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return f(0, n - 1, values, dp);
    }
};