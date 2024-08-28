class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0, maxLen = 0, n = nums.size();

        int i = 0, j = 0, len = 0;
        while (j < n) {
            if (nums[j] == 0) {
                zeros++;
            }

            while (zeros > k) {
                if (nums[i] == 0) {
                    zeros--;
                }
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            
            j++;
        }

        return maxLen;
    }
};