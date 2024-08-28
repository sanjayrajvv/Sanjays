class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;

        int minimumOperations = INT_MAX;
        int windowSum = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            windowSum += nums[r];

            while (windowSum > target && l <= r) {
                windowSum -= nums[l];
                l++;
            }

            if (windowSum == target) {
                minimumOperations = min(minimumOperations, n - (r - l + 1));
            }
        }

        return minimumOperations == INT_MAX ? -1 :  minimumOperations;
    }
};