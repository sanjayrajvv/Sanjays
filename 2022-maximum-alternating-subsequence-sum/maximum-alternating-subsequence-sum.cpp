class Solution {
private:
    long long f(int i, bool turn, vector<int>& nums, vector<vector<long long>>& dp) {
        if (i < 0) {
            return 0;
        }

        if (dp[i][turn] != -1) {
            return dp[i][turn];
        }

        long long maxSum = 0;
        if (turn) {
            long long notTake = f(i - 1, turn, nums, dp);
            long long take = nums[i];
            take += f(i - 1, !turn, nums, dp);
            
            maxSum = max(notTake, take);
        } else {
            long long notTake = f(i - 1, turn, nums, dp);
            long long take = -nums[i];
            take += f(i - 1, !turn, nums, dp);

            maxSum = max(notTake, take);
        }

        return dp[i][turn] = maxSum;
    }
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));

        return f(n - 1, 1, nums, dp);
    }
};
