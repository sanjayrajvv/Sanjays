class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        
        // Step 1: Precompute the palindrome information
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i <= 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }

        // Step 2: Initialize the dp array
        vector<int> dp(n, INT_MAX);
        for (int i = n - 1; i >= 0; --i) {
            if (isPal[i][n - 1]) {
                dp[i] = 0;  // No cut needed if s[i...n-1] is a palindrome
            } else {
                for (int j = i; j < n; ++j) {
                    if (isPal[i][j]) {
                        dp[i] = min(dp[i], 1 + dp[j + 1]);
                    }
                }
            }
        }

        return dp[0];
    }
};