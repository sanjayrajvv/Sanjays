class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();

        int maxEnergy = INT_MIN;
        vector<int> dp(n + k, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] =  dp[i + k] + energy[i];
            maxEnergy = max(maxEnergy, dp[i]);
        }

        return maxEnergy;
    }
};