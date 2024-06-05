class Solution {
    int f(int index, int n, int k, vector<int> &arr, vector<int> &dp) {
        if (index == n) return 0;

        if (dp[index] != -1) return dp[index];

        int maxAns = INT_MIN, len = 0, maxi = INT_MIN;
        for (int j = index; j < min(n, index + k); j++) {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = (len * maxi) + f(j + 1, n, k, arr, dp);
            maxAns = max(maxAns, sum);
        }

        return dp[index] = maxAns;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n + 1, 0);

        for (int index = n - 1; index >= 0; index--) {
            int maxAns = INT_MIN, len = 0, maxi = INT_MIN;
            for (int j = index; j < min(n, index + k); j++) {
                len++;
                maxi = max(maxi, arr[j]);
                int sum = (len * maxi) + dp[j + 1];
                maxAns = max(maxAns, sum);
            }

            dp[index] = maxAns;
        }

        return dp[0];
    }
};