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

private:
    int f(int i, int remainder, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return remainder == 0 ? 0 : INT_MIN;
        }

        if (dp[i][remainder] != -1) {
            return dp[i][remainder];
        }

        int take = nums[i] + f(i + 1, (remainder + nums[i]) % 3, nums, dp);
        int notTake = f(i + 1, remainder, nums, dp);

        return dp[i][remainder] = max(take, notTake);
    }
};