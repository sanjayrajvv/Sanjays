class Solution {
private:
    bool helper(int i, int j, string s, string p, vector<vector<int>> &dp) {
        if (i >= s.size() && j >= p.size()) return true; //fully matched
        if (j >= p.size()) return false; //expression exhausted

        if (dp[i][j] != -1) return dp[i][j];

        bool match = i < s.size() and (s[i] == p[j] || p[j] == '.');
        if ((j + 1) < p.size() && p[j + 1] == '*') {
            return dp[i][j] = helper(i, j + 2, s, p, dp) || 
                            (match and helper(i + 1, j, s, p, dp));
        }
        if (match) return dp[i][j] = helper(i + 1, j + 1, s, p, dp);
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return helper(0, 0, s, p, dp);
    }
};