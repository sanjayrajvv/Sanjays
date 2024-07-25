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
        vector<bool> dp(n + 1, false);
        dp[n] = true;

        for (int index = n - 1; index >= 0; --index) {
            for (int len = 2; len <= 3; ++len) {
                if (index + len <= n && isGood(nums, index, index + len - 1)) {
                    if (dp[index + len]) {
                        dp[index] = true;
                        break; // Exit early since we found a valid partition
                    }
                }
            }
        }

        return dp[0];
    }
};
