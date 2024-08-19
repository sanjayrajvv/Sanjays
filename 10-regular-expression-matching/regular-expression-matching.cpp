class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return f(0, 0, s, p, dp);
    }

private:
    bool f(int i, int j, string s, string p, vector<vector<int>>& dp) {
        if (i >= s.size() && j >= p.size()) return true;
        if (j >= p.size()) return false;

        if (dp[i][j] != -1) return dp[i][j];

        bool match = (i < s.size()) && (s[i] == p[j] || p[j] == '.');
        if (j + 1 < p.size() && p[j + 1] == '*') {
            return dp[i][j] = f(i, j + 2, s, p, dp) || 
                              (match && f(i + 1, j, s, p, dp));
        }

        if (match) return dp[i][j] = f(i + 1, j + 1, s, p, dp);

        return dp[i][j] = false;
    }
};