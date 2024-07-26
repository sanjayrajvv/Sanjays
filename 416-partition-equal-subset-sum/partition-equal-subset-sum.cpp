class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        int target = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for (int i = 0; i < n; i++) dp[i][0] = true;
        if (nums[0] <= target) dp[0][nums[0]] = true;

        for (int index = 1; index < n; index++) {
            for (int currTarget = 0; currTarget <= target; currTarget++) {
                bool notTake = dp[index - 1][currTarget];
                bool take = false; 
                if (currTarget >= nums[index]) {
                    take = dp[index - 1][currTarget - nums[index]];
                }

                dp[index][currTarget] = notTake || take;
            }
        }

        return dp[n - 1][target];
    }
};