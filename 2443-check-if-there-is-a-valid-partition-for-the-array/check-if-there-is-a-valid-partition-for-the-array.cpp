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

    bool f(int index, vector<int> &nums, vector<int> &dp) {
        if (index == nums.size()) return true;
        if (index > nums.size()) return false;

        if (dp[index] != -1) return dp[index];

        for (int i = index; i < min(index + 3, (int)nums.size()); i++) {
            if (isGood(nums, index, i)) {
                if (f(i + 1, nums, dp)) {
                    return dp[index] = true;
                }
            }
        }

        return dp[index] = false;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n + 1, -1);  // Change size to n+1
        dp[n] = true;  // Initialize the end state as true

        return f(0, nums, dp);
    }
};
