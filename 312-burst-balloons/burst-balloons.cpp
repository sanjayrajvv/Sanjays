class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i > 0; i--) {
            for (int j = 1; j <= n; j++) {
                if (i > j) continue;

                int maxCoins = -1e9;
                for (int index = i; index <= j; index++) {
                    int coins = nums[i - 1] * nums[index] * nums[j + 1] 
                    + dp[i][index - 1] + dp[index + 1][j];

                    maxCoins = max(maxCoins, coins);
                } 

                dp[i][j] = maxCoins;
            }
        }

        return dp[1][n];
    }
};