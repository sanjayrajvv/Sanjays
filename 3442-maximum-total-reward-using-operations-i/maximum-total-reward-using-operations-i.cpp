class Solution {
private:
    int f(int i, int totalReward, vector<int>& rewardValues, vector<vector<int>> &dp) {
        if (i == rewardValues.size()) {
            return totalReward;
        }

        if (dp[i][totalReward] != -1) {
            return dp[i][totalReward];
        }

        int notTake = f(i + 1, totalReward, rewardValues, dp);
        int take = 0;
        if (totalReward < rewardValues[i]) {
            take = f(i + 1, totalReward + rewardValues[i], rewardValues, dp);
        }

        return dp[i][totalReward] = max(notTake, take);
    }
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();

        sort(rewardValues.begin(), rewardValues.end());

        int total = accumulate(rewardValues.begin(), rewardValues.end(), 0);

        vector<vector<int>> dp(n, vector<int>(4001, -1));

        return f(0, 0, rewardValues, dp);
    }
};