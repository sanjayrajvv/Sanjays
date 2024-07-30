class Solution {
private:
    int f(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp) {
        if (i >= nums1.size() || j >= nums2.size()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int notMatch = f(i + 1, j, nums1, nums2, dp);
        int match = 0;
        for (int index = j; index < nums2.size(); index++) {
            if (nums1[i] == nums2[index]) {
                match = 1 + f(i + 1, index + 1, nums1, nums2, dp);
                break;
            }
        }

        return dp[i][j] = max(notMatch, match);
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return f(0, 0, nums1, nums2, dp);
    }
};