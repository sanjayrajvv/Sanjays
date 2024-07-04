class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int maxSum = nums[0], currMax = nums[0];
        int minSum = nums[0], currMin = nums[0];
        int total = nums[0];
        
        for (int i = 1; i < n; ++i) {
            currMax = max(nums[i], currMax + nums[i]);
            maxSum = max(maxSum, currMax);
            
            currMin = min(nums[i], currMin + nums[i]);
            minSum = min(minSum, currMin);
            
            total += nums[i];
        }
        
        if (maxSum < 0) {
            return maxSum; // All numbers are negative
        }
        
        return max(maxSum, total - minSum);
    }
};
