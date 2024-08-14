class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(3, -1));

        return f(0, 0, nums, dp);
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