class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n + 2, 0);

        for (int i = n - 1; i >= 0; i--) {
            int notTake = dp[i + 1];
            int take = nums[i] + dp[i + 2];

            dp[i] = max(take, notTake);
        }

        return dp[0];
    }

private:
    int f(int i, vector<int>& nums, vector<int>& dp) {
        if (i >= nums.size()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int notTake = f(i + 1, nums, dp);
        int take = nums[i] + f(i + 2, nums, dp);

        return dp[i] = max(take, notTake);
    }
};