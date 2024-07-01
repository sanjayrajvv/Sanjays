class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int prefixSum = 0;

        int i = 0, j = 0, windowSize = INT_MAX;
        while (j < n) {
            prefixSum += nums[j];
            j++;

            while (prefixSum >= target) {
                windowSize = min(windowSize, j - i);
                prefixSum -= nums[i];
                i++;
            }
        }

        return (windowSize == INT_MAX) ? 0 : windowSize;
    }
};