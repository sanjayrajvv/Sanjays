class Solution {
    bool f(int i, int j, string s, string p, vector<vector<int>> &dp) {
        //Base cases
        if (i < 0 && j < 0) return true; //string and pattern exhaustedd
        if (j < 0 && i >= 0) return false; //pattern exhausted
        if (i < 0 && j >= 0) {             //string exhausted
            while (j >= 0) {
                if (p[j] != '*') return false;
                j--;
            }

            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j] || p[j] == '?') return dp[i][j] = f(i - 1, j - 1, s, p, dp);
        if (p[j] == '*') return dp[i][j] = f(i - 1, j, s, p, dp) | f(i, j - 1, s, p, dp);
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));

        dp[0][0] = 1;

        

        for (int j = 1; j <= m; j++) {
            bool flag = true;
            for (int jj = 1; jj <= j; jj++) {
                if (p[jj - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            
            dp[0][j] = flag;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*') dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};