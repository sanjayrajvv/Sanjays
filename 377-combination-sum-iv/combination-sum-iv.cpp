class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();

        vector<long long> dp(target + 1, 0);

        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            int count = 0;
            for (int num : nums) {
                if (i >= num) count += dp[i - num];
            }

            dp[i] = count;
        }

        return dp[target];
    }
};
