class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int notMatch = dp[i + 1][j];
                int match = 0;
                for (int index = j; index < nums2.size(); index++) {
                    if (nums1[i] == nums2[index]) {
                        match = 1 + dp[i + 1][index + 1];
                        break;
                    }
                }

                dp[i][j] = max(notMatch, match);
            }
        }

        return dp[0][0];
    }
};