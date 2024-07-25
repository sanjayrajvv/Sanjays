class Solution {
private:
    bool isGood(vector<int> &nums, int l, int r) {
        int len = r - l + 1;
        if (len == 2) {
            return nums[l] == nums[r];
        } else if (len == 3) {
            return (nums[l] == nums[l + 1] && nums[l + 1] == nums[l + 2]) ||
                   (nums[l] + 1 == nums[l + 1] && nums[l + 1] + 1 == nums[l + 2]);
        }
        return false;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return false;

        // Initialize the last three dp values
        bool dp1 = true;   // dp[n]
        bool dp2 = false;  // dp[n-1]
        bool dp3 = false;  // dp[n-2]

        for (int index = n - 1; index >= 0; --index) {
            bool current_dp = false;
            if (index + 2 <= n && isGood(nums, index, index + 1)) {
                current_dp = dp2;
            }
            if (index + 3 <= n && isGood(nums, index, index + 2)) {
                current_dp = current_dp || dp3;
            }

            // Shift dp values for the next iteration
            dp3 = dp2;
            dp2 = dp1;
            dp1 = current_dp;
        }

        return dp1;
    }
};
