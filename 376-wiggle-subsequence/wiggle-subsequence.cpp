class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return f(0, -1, nums, dp); 
    }

private:
    int f(int index, int prevIndex, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if (index == n) {
            return 0;
        }

        if (dp[index][prevIndex + 1] != -1) {
            return dp[index][prevIndex + 1];
        }

        int notTake = f(index + 1, prevIndex, nums, dp);
        int take = INT_MIN;

        if (prevIndex == -1 || 
            (nums[index] > nums[prevIndex] && 
             (index == n - 1 || nums[index + 1] < nums[index])) || 
            (nums[index] < nums[prevIndex] && 
             (index == n - 1 || nums[index + 1] > nums[index]))) {
            take = 1 + f(index + 1, index, nums, dp);
        }

        return dp[index][prevIndex + 1] = max(take, notTake);
    }
};
