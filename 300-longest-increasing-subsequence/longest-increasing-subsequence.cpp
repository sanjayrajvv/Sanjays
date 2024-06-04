class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int index = 0; index < n; index++) {
            for (int prev_index = 0; prev_index < index; prev_index++) {
                if (nums[prev_index] < nums[index]) {
                    dp[index] = max(1 + dp[prev_index], dp[index]);
                }
            }
        }

        int len = INT_MIN;
        for (int i = 0; i < n; i++) {
            len = max(len, dp[i]);
        }

        return len;
    }
};