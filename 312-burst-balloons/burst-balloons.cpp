class Solution {
private:
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int maxPoints = INT_MIN;
        for (int index = i; index <= j; index++) {
            int cost = nums[i - 1] * nums[index] * nums[j + 1] +
                        f(i, index - 1, nums, dp) +
                        f(index + 1, j, nums, dp);
            maxPoints = max(maxPoints, cost);
        }

        return dp[i][j] = maxPoints;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size() - 2;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return f(1, n, nums, dp);
    }
};