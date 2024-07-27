class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n  = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);

        sort(nums.begin(), nums.end());

        for (int index = 1; index < n; index++) {
            hash[index] = index;
            for (int prevIndex = 0; prevIndex < index; prevIndex++) {
                if (nums[index] % nums[prevIndex] == 0 && 
                ((1 + dp[prevIndex]) > dp[index])) {
                    dp[index] = 1 + dp[prevIndex];
                    hash[index] = prevIndex;
                }
            }
        }

        int len = INT_MIN;
        int lastIndex = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] > len) {
                len = dp[i];
                lastIndex = i;
            }
        }

        vector<int> ans;
        while (hash[lastIndex] != lastIndex) {
            ans.push_back(nums[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        ans.push_back(nums[lastIndex]);

        return ans;
    }
};