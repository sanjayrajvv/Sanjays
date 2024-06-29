class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> dp(n, 1), path(n);

        int maxLength = 1, maxIndex = 0;
        for (int i = 0; i < n; i++) {
            path[i] = i;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if ((1 + dp[j]) > dp[i]) {
                        dp[i] = 1 + dp[j];
                        path[i] = j;
                    }
                }
            }

            if (dp[i] > maxLength) {
                    maxLength = dp[i];
                    maxIndex = i;
            }
        }

        vector<int> ans;
        while (path[maxIndex] != maxIndex) {
            ans.push_back(nums[maxIndex]);
            maxIndex = path[maxIndex];
        }
        ans.push_back(nums[maxIndex]);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};