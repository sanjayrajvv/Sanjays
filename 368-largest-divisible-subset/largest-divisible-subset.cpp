class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1), hash(n), subsequence;

        for (int index = 0; index < n; index++) {
            hash[index] = index;
            for (int prev_index = 0; prev_index < index; prev_index++) {
                if (nums[index] % nums[prev_index] == 0 && 1 + dp[prev_index] > dp[index]) {
                    dp[index] = 1 + dp[prev_index];
                    hash[index] = prev_index;
                }
            }
        }
        
        int len = INT_MIN, last_index = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] > len) {
                len = dp[i];
                last_index = i;
            }
        }
        
        subsequence.push_back(nums[last_index]);
        while (hash[last_index] != last_index) {
            last_index = hash[last_index];
            subsequence.push_back(nums[last_index]);
        }
        
        return subsequence;
    }
};