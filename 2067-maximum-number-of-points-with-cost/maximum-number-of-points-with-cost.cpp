class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        // Initialize the dp array with the last row values
        for (int j = 0; j < n; j++) {
            dp[m-1][j] = points[m-1][j];
        }

        for (int i = m - 2; i >= 0; i--) {
            vector<long long> left(n, 0), right(n, 0);

            // Calculate left-to-right sweep
            left[0] = dp[i+1][0];
            for (int j = 1; j < n; j++) {
                left[j] = max(left[j-1] - 1, dp[i+1][j]);
            }

            // Calculate right-to-left sweep
            right[n-1] = dp[i+1][n-1];
            for (int j = n - 2; j >= 0; j--) {
                right[j] = max(right[j+1] - 1, dp[i+1][j]);
            }

            // Update dp values for the current row
            for (int j = 0; j < n; j++) {
                dp[i][j] = points[i][j] + max(left[j], right[j]);
            }
        }

        long long maxSum = 0;
        for (int j = 0; j < n; j++) {
            maxSum = max(maxSum, dp[0][j]);
        }

        return maxSum;
    }
};
