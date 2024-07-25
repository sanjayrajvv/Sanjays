class Solution {
private:
    int f(int target, vector<int> &nums, vector<int> &dp) {
        if (target < 0) return 0;
        if (target == 0) return 1;

        if (dp[target] != -1) return dp[target];

        int count = 0;
        for (int num : nums) {
            count += f(target - num, nums, dp);
        }

        return dp[target] = count;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(target + 1, -1);

        return f(target, nums, dp);
    }
};