class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n, -1);

        return f(0, s, dp);
    }

private:
    int f(int i, string s, vector<int>& dp) {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;

        if (dp[i] != -1) return dp[i];

        int ways = f(i + 1, s, dp);
        if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')) {
            ways += f(i + 2, s, dp);
        }

        return dp[i] = ways;
    }
};