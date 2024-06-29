class Solution {
    int f(int i, int n, vector<int> &arr, int k, vector<int> &dp) {
        if (i == n) return 0;

        if (dp[i] != -1) return dp[i];

        int subSum = -1e9, len = 0, maxAns = -1e9;
        for (int j = i; j < min(n, i + k); j++) {
            len++;
            subSum = max(subSum, arr[j]);

            maxAns = max(maxAns, (len * subSum) + f(j + 1, n, arr, k, dp));
        }

        return dp[i] = maxAns;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int subSum = -1e9, len = 0, maxAns = -1e9;
            for (int j = i; j < min(n, i + k); j++) {
                len++;
                subSum = max(subSum, arr[j]);

                maxAns = max(maxAns, (len * subSum) + dp[j + 1]);
            }

            dp[i] = maxAns;
        }

        return dp[0];
    }
};