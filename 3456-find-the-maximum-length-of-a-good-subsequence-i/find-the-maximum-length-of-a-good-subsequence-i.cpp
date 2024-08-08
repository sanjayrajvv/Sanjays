class Solution {
private:
    int f(int index, int prevIndex, vector<int> &nums, 
    int k, vector<vector<int>> &dp) {
        if (index == nums.size()) {
            return 0;
        }

        if (dp[prevIndex + 1][k] != -1) {
            return dp[prevIndex + 1][k];
        }

        // Take
        int take = 0;
        if (prevIndex != -1 && nums[prevIndex] != nums[index]) {
            if (k > 0) {
                take = 1 + f(index + 1, index, nums, k - 1, dp);
            }
        } else if (prevIndex == -1 || nums[prevIndex] == nums[index]) {
            take = 1 + f(index + 1, index, nums, k, dp);
        }

        // Not take
        int notTake = f(index + 1, prevIndex, nums, k, dp);

        return dp[prevIndex + 1][k] = max(take, notTake);
    }
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        return f(0, -1, nums, k, dp);
    }
};