class Solution {
private:
    int f(int i, int n, string s, vector<int> &dp) {
        if (i == n) return 1;
        if (s[i] == '0') return 0;

        if (dp[i] != -1) return dp[i];

        int ways = f(i + 1, n, s, dp);
        if ((i + 1 < n) && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            ways += f(i + 2, n, s, dp);
        }

        return dp[i] = ways;
    }
public:
    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n, -1);

        return f(0, n, s, dp);
    }
};