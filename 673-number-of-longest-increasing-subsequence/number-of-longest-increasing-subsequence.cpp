class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);

        int maxLen = 1;
        for (int index = 1; index < n; index++) {
            for (int prevIndex = 0; prevIndex < index; prevIndex++) {
                if (nums[prevIndex] < nums[index]) {
                    if (1 + dp[prevIndex] > dp[index]) {
                        dp[index] = 1 + dp[prevIndex];
                        count[index] = count[prevIndex];
                    } else if (1 + dp[prevIndex] == dp[index]) {
                        count[index] += count[prevIndex];
                    }
                }
            }
            maxLen = max(maxLen, dp[index]);
        }

        int numberofMaxLen = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLen) {
                numberofMaxLen += count[i];
            }
        }

        return numberofMaxLen;
    }
};