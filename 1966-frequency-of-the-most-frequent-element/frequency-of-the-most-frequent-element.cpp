class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

        // Sort the array to consider increasing frequencies
        sort(nums.begin(), nums.end());

        int maxLen = 0;
        int l = 0;
        long long total = 0;  // Use long long to avoid overflow

        for (int r = 0; r < n; r++) {
            // Add the current number to the total
            total += nums[r];

            // Check if the current window can be made valid
            while ((long long)nums[r] * (r - l + 1) > total + k) {
                total -= nums[l];
                l++;
            }

            // Update maxLen if the current window is valid
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
