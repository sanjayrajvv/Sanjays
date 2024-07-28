class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size() - 2;

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                if (i > j) continue;

                int maxPoints = INT_MIN;
                for (int index = i; index <= j; index++) {
                    int cost = nums[i - 1] * nums[index] * nums[j + 1] +
                                dp[i][index - 1] +
                                dp[index + 1][j];
                    maxPoints = max(maxPoints, cost);
                }

                dp[i][j] = maxPoints;
            }
        }

        return dp[1][n];
    }
};