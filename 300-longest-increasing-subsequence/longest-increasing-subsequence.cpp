class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int maxLen = 1;
        for (int index = 1; index < n; index++) {
            for (int prevIndex = 0; prevIndex < index; prevIndex++) {
                if (nums[index] > nums[prevIndex]) {
                    dp[index] = max(dp[index], 1 + dp[prevIndex]);
                }
            }
            maxLen = max(maxLen, dp[index]);
        }

        return maxLen;
    }
};