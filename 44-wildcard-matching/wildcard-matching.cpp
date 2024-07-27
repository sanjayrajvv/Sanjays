class Solution {
public:
    bool isMatch(string s, string p) {
        int sz = s.size(), pz = p.size();

        vector<vector<bool>> dp(sz + 1, vector<bool>(pz + 1, 0));
        dp[0][0] = true;
        for (int j = 1; j <= pz; j++) {
            bool flag = true;
            for (int jj = 1; jj <= j; jj++) {
                if (p[jj - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for (int i = 1; i <= sz; i++) {
            for (int j = 1; j <= pz; j++) {
                bool match = false;
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    match = dp[i - 1][j - 1];
                } 
                if (p[j - 1] == '*') {
                    match = dp[i - 1][j] | dp[i][j - 1];
                } 
                dp[i][j] = match;
            }
        }

        return dp[sz][pz];
    }
};