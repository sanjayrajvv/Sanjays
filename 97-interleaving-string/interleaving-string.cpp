/*class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();

        if (m + n != s3.size()) return false;

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[m][n] = true;

        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                
                bool l = false;
                if (i < m && s1[i] == s3[i + j]) {
                    l = dp[i + 1][j];
                }

                bool r = false;
                if (j < n && s2[j] == s3[i + j]) {
                    r = dp[i][j + 1];
                }

                dp[i][j] = l | r;
            }
        }


        return dp[0][0];
    }
};*/


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();

        if (m + n != s3.size()) return false;

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[m][n] = true;

        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                
                if (i < m && s1[i] == s3[i + j]) {
                    dp[i][j] = dp[i + 1][j];
                }

                if (j < n && s2[j] == s3[i + j]) {
                    dp[i][j] = dp[i][j] || dp[i][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};
