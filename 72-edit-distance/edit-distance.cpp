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

        vector<vector<int>> dp(n, vector<int>(m , -1));

        return countDist(n - 1, m - 1, word1, word2, dp);
    }
};