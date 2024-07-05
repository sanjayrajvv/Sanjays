class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], currMax = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currMax = max(nums[i], currMax + nums[i]);
            maxSum = max(maxSum, currMax);
        }

        return maxSum;
    }
};