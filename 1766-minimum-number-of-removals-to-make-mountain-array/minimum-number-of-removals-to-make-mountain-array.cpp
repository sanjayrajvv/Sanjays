class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp1(n, 1);
        for (int index = 1; index < n; index++) {
            for (int prevIndex = 0; prevIndex < index; prevIndex++) {
                if (nums[prevIndex] < nums[index]) {
                    dp1[index] = max(dp1[index], 1 + dp1[prevIndex]);
                }
            }
        }

        vector<int> dp2(n, 1);
        for (int index = n - 2; index >= 0; index--) {
            for (int prevIndex = n - 1; prevIndex > index; prevIndex--) {
                if (nums[prevIndex] < nums[index]) {
                    dp2[index] = max(dp2[index], 1 + dp2[prevIndex]);
                }
            }
        }

        int longestBitonic = 0;
        for (int i = 0; i < n; i++) {
            if (dp1[i] > 1 && dp2[i] > 1) { // Ensure both sides of the peak are valid
                longestBitonic = max(longestBitonic, dp1[i] + dp2[i] - 1);
            }
        }

        return n - longestBitonic;
    }
};