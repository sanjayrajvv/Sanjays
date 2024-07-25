class Solution {
private:
    bool isGood(vector<int> &nums, int l, int r) {
        if (r - l + 1 == 2) {
            if (nums[l] == nums[r]) {
                return true;
            }
        } else if (r - l + 1 == 3) {
            if (nums[l] == nums[l + 1] && nums[l + 1] == nums[l + 2]) {
                return true;
            } else if (nums[l] + 1 == nums[l + 1] && nums[l + 1] + 1 == nums[l + 2]) {
                return true;
            }
        }
        return false;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();

        vector<bool> dp(n + 1, 0);  // Change size to n+1
        dp[n] = true;  // Initialize the end state as true

        for (int index = n - 1; index >= 0; index--) {
            for (int i = index; i < min(index + 3, (int)nums.size()); i++) {
                if (isGood(nums, index, i)) {
                    if (dp[i + 1]) {
                        dp[index] = true;
                    }
                }
            }
        }

        return dp[0];
    }
};
