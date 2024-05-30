class Solution {
    int lengthofSubsequence(int index1, int index2, string text1, string text2, vector<vector<int>> &dp) {
        if (index1 < 0 || index2 < 0) return 0;

        if (dp[index1][index2] != -1) return dp[index1][index2];

        if (text1[index1] == text2[index2]) {
            return dp[index1][index2] = 1 + lengthofSubsequence(index1 - 1, index2 - 1, text1, text2, dp);
        } else {
            return dp[index1][index2] = max(lengthofSubsequence(index1 - 1, index2, text1, text2, dp), lengthofSubsequence(index1, index2 - 1, text1, text2, dp));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size(), l2 = text2.size();

        vector<int> prev(l2 + 1, 0), curr(l2 + 1, 0);

        for (int index1 = 1; index1 <= l1; index1++) {
            for (int index2 = 1; index2 <= l2; index2++) {

                if (text1[index1 - 1] == text2[index2 - 1]) {
                    curr[index2] = 1 + prev[index2 - 1];
                } else {
                    curr[index2] = max(prev[index2], curr[index2 - 1]);
                }
            }

            prev = curr;
        }

        return prev[l2];
    }
};