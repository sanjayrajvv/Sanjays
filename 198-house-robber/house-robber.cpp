class Solution {
private:
    int f(int index, vector<int> &nums, vector<int> &dp) {
        if (index < 0) return 0;
        if (index == 0) return nums[index];

        if (dp[index] != -1) return dp[index];

        int pick = nums[index] + f(index - 2, nums, dp);
        int notPick = f(index - 1, nums, dp);

        return dp[index] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        return f(n - 1, nums, dp);
    }
};