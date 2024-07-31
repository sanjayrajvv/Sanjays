class Solution {
    int f(int i, int total, int target, int sum, 
    vector<int>& stones, vector<vector<int>> &dp) {
        if (total >= target || i == 0) {
            return abs(total - (sum - total));
        }

        if (dp[i][total] != -1) return dp[i][total];

        int notPick = f(i - 1, total, target, sum, stones, dp);
        int pick = f(i - 1, total + stones[i], target, sum, stones, dp);

        return dp[i][total] = min(notPick, pick);
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = ceil(double(sum) / 2);  

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(n - 1, 0, target, sum, stones, dp);
    }
};
