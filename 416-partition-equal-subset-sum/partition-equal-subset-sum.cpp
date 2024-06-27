class Solution {
    bool f(int index, int target, vector<int> &nums, vector<vector<int>> &dp) {
        if (target == 0) return true;
        if (index == 0) return (nums[0] == target);

        if (dp[index][target] != -1) return dp[index][target];

        int notTake = f(index - 1, target, nums, dp);
        int take = false;
        if (nums[index] <= target) take = f(index - 1, target - nums[index], nums, dp);

        return dp[index][target] = take | notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 == 1) return false;

        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        for (int i = 0; i < n; i++) dp[i][0] = true;

        for (int index = 1; index < n; index++) {
            for (int t = 0; t <= target; t++) {
                int notTake = dp[index - 1][t];
                int take = false;
                if (nums[index] <= t) take = dp[index - 1][t - nums[index]];

                dp[index][t] = take | notTake;
            }
        }

        return dp[n - 1][target];
    }
};