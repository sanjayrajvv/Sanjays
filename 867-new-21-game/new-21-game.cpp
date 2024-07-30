class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) return 1.0;

        vector<double> dp(n + 1, 0.0);
        double sum = 0.0;
        
        // Initialize dp values from k to n
        for (int i = k; i <= n; i++) {
            dp[i] = 1.0;
        }
        
        // Calculate the initial window sum
        for (int i = k; i < k + maxPts && i <= n; i++) {
            sum += dp[i];
        }

        // Fill dp array from k-1 to 0
        for (int i = k - 1; i >= 0; i--) {
            dp[i] = sum / maxPts;
            sum += dp[i];
            if (i + maxPts <= n) {
                sum -= dp[i + maxPts];
            }
        }

        return dp[0];
    }
};
