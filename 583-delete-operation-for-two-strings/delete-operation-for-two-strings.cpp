class Solution {
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size(), l2 = text2.size();

        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

        for (int index1 = 1; index1 <= l1; index1++) {
            for (int index2 = 1; index2 <= l2; index2++) {

                if (text1[index1 - 1] == text2[index2 - 1]) {
                    dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                } else {
                    dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
                }
            }
        }

        return dp[l1][l2];
    }
public:
    int minDistance(string word1, string word2) {
        int lcs = longestCommonSubsequence(word1, word2);
        int n = word1.size(), m = word2.size();

        return (n + m - 2 * lcs);
    }
};