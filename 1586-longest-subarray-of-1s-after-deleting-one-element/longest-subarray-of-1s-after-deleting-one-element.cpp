class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0, maxLen = 0, zeros = 0;
        while (j < n) {
            if (nums[j] == 0) {
                zeros++;
            }

            if (zeros > 1) {
                if (nums[i] == 0) {
                    zeros--;
                }
                i++;
            }

            maxLen = max(maxLen, j - i);
            j++;
        }

        return maxLen;
    }
};