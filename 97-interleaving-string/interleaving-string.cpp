class Solution {
    bool f(int i, int j, string s1, string s2, string s3, vector<vector<int>> &dp) {
        if (i == s1.size() && j == s2.size()) return true;
        if (i > s1.size() || j > s2.size()) return false;

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
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 + n2 != s3.size()) return false;

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        return f(0, 0, s1, s2, s3, dp);
    }
};