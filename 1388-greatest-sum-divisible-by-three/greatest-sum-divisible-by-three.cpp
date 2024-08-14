class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(3, INT_MIN));
        dp[n][0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int remainder = 0; remainder < 3; remainder++) {
                int take = nums[i] + dp[i + 1][(remainder + nums[i]) % 3];
                int notTake = dp[i + 1][remainder];

                dp[i][remainder] = max(take, notTake);
            }
        }

        return dp[0][0];
    }
};