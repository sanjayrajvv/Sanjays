class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();

        if (m + n != s3.size()) return false;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return f(0, 0, s1, s2, s3, dp);
    }

private:
    bool f(int i, int j, string s1, string s2, string s3, 
            vector<vector<int>>& dp) {
        if (i + j == s3.size()) return true;
        if (s1[i] != s3[i + j] && s2[j] != s3[i + j]) return false;

        if (dp[i][j] != -1) return dp[i][j];

        bool l = false;
        if (s1[i] == s3[i + j]) {
            l = f(i + 1, j, s1, s2, s3, dp);
        }

        bool r = false;
        if (s2[j] == s3[i + j]) {
            r = f(i, j + 1, s1, s2, s3, dp);
        }

        return dp[i][j] = l | r;
    }
};