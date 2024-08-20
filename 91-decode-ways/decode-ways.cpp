class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n + 1, 1);

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }
                
            int ways = dp[i + 1];
            if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')) {
                ways += dp[i + 2];
            }

            dp[i] = ways;
        }

        return dp[0];
    }
};