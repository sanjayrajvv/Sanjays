class Solution {
private:
    int helper(int i, int j, string word1, string word2, vector<vector<int>> &dp) {
        if (i == 0) return j;
        if (j == 0) return i;

        if (dp[i][j] != -1) return dp[i][j];

        int minOp;
        if (word1[i - 1] == word2[j - 1]) {
            minOp =  helper(i - 1, j - 1, word1, word2, dp);
        } else {
            minOp = 1 + min({helper(i - 1, j, word1, word2, dp), 
            helper(i, j - 1, word1, word2, dp), helper(i - 1, j - 1, word1, word2, dp)});
        }
        return dp[i][j] = minOp;
    }
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        return helper(n1, n2, word1, word2, dp);
    }
};