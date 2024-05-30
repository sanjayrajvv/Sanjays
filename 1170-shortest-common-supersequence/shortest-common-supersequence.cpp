class Solution {
    void longestCommonSubsequence(string text1, string text2, vector<vector<int>> &dp, int l1, int l2) {

        for (int index1 = 1; index1 <= l1; index1++) {
            for (int index2 = 1; index2 <= l2; index2++) {

                if (text1[index1 - 1] == text2[index2 - 1]) {
                    dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                } else {
                    dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
                }
            }
        }
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
    int l1 = str1.size(), l2 = str2.size();

    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0)); 

    longestCommonSubsequence(str1, str2, dp, l1, l2);

    int i = l1, j = l2;
    string ans;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            ans.push_back(str1[i - 1]);
            i--; j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
            } else {
                ans.push_back(str2[j - 1]);
                j--;
            }
        }
    }

    while (i > 0) {
        ans.push_back(str1[i - 1]);
        i--;
    }

    while (j > 0) {
        ans.push_back(str2[j - 1]);
        j--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

};