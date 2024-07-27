class Solution {
public:
    int numDistinct(string s, string t) {
        int s_size = s.size(), t_size = t.size();

        vector<vector<double>> dp(s_size + 1, vector<double>(t_size + 1, 0));
        for (int i = 0; i <= s_size; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= s_size; i++) {
            for (int j = 1; j <= t_size; j++) { 
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return (int)dp[s_size][t_size];
    }
};