class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int longest = 1;
        for (int index = 1; index < n; index++) {
            for (int prevIndex = 0; prevIndex < index; prevIndex++) {
                if (nums[prevIndex] < nums[index]) {
                    dp[index] = max(1 + dp[prevIndex], dp[index]);
                }
            }
            longest = max(longest, dp[index]);
        }

        return longest;
    }
};