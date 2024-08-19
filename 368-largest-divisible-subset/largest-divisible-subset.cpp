class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> parent(n);

        for (int index = 0; index < n; index++) {
            parent[index] = index;
            for (int prevIndex = 0; prevIndex < index; prevIndex++) {
                if (nums[index] % nums[prevIndex] == 0) {
                    if (dp[index] < 1 + dp[prevIndex]) {
                        dp[index] = 1 + dp[prevIndex];
                        parent[index] = prevIndex;
                    }
                }
            }
        }

        int length = 1, lastIndex = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] > length) {
                length = dp[i];
                lastIndex = i;
            }
        }

        vector<int> largestSubset;
        while (lastIndex != parent[lastIndex]) {
            largestSubset.push_back(nums[lastIndex]);
            lastIndex = parent[lastIndex];
        }
        largestSubset.push_back(nums[lastIndex]);

        reverse(largestSubset.begin(), largestSubset.end());

        return largestSubset;
    }
};