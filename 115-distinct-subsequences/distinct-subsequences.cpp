class Solution {
    int helper(int i, int j, string s, string t, vector<vector<int>> &dp) {
        if (j == 0) return 1;
        if (i == 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i - 1] == t[j - 1]) {
            return dp[i][j] = helper(i - 1, j - 1, s, t, dp) + helper(i - 1, j, s, t, dp);
        } else {
            return dp[i][j] = helper(i - 1, j, s, t, dp);
        }
    }
public:
    int numDistinct(string s, string t) {
        int s_size = s.size(), t_size = t.size();

        vector<vector<int>> dp(s_size + 1, vector<int>(t_size + 1, -1));

        return helper(s_size, t_size, s, t, dp);
    }
};