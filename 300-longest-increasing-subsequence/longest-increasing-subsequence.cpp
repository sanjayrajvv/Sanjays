class Solution {
    int f(int index, int prev_index, int n,vector<int> &nums, vector<vector<int>> &dp) {
        if (index == n) return 0;

        if (dp[index][prev_index + 1] != -1) return dp[index][prev_index + 1];

        int notTake = f(index + 1, prev_index, n, nums, dp);
        int Take = 0;
        if (prev_index == -1 || nums[index] > nums[prev_index]) {
            Take = 1 + f(index + 1, index, n, nums, dp);
        }

        return dp[index][prev_index + 1] = max(notTake, Take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> ahead(n + 1, 0), curr(n + 1, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int prev_index = index - 1; prev_index >= -1; prev_index--) {
                int notTake = ahead[prev_index + 1];
                int Take = 0;
                if (prev_index == -1 || nums[index] > nums[prev_index]) {
                    Take = 1 + ahead[index + 1];
                }

                curr[prev_index + 1] = max(notTake, Take);
            }

            ahead = curr;
        }

        return ahead[0];
    }
};