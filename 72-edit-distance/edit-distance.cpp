class Solution {
    int countDist(int i, int j, string word1, string word2, vector<vector<int>> &dp) {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;

        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j]) return dp[i][j] = countDist(i - 1, j - 1, word1, word2, dp);
        else {
            return dp[i][j] = min({(1 + countDist(i, j - 1, word1, word2, dp)), 
            (1 + countDist(i - 1, j, word1, word2, dp)), 
            (1 + countDist(i - 1, j - 1, word1, word2, dp))});
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1 , -1));

        for (int i = 0; i <= n; i++) dp[i][0] = i;
        for (int j = 0; j <= m; j++) dp[0][j] = j;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) 
                    dp[i][j] = dp[i - 1][j - 1]; 
                else {
                    dp[i][j] = min({(1 + dp[i][j - 1]), 
                    (1 + dp[i - 1][j]),
                    (1 + dp[i - 1][j - 1])});
                }
            }
        }

        return dp[n][m];
    }
};