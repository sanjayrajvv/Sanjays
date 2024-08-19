class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return f(m, n, s, t, dp);
    }

private:
    int f(int i, int j, string s, string t, vector<vector<int>>& dp) {
        if (j == 0) return 1;
        if (i == 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i - 1] == t[j - 1]) {
            return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);
        } else {
            return dp[i][j] = f(i - 1, j, s, t, dp);
        }
    }
};