class Solution {
    bool isPal(int i, int j, string p, vector<vector<int>> &dp2) {
        if (dp2[i][j] != -1) return dp2[i][j];

        for (int k = 0; k < p.size() / 2; k++) {
            if (p[k] != p[p.size() - 1 - k]) return dp2[i][j] = false;
        }

        return dp2[i][j] = true;
    }
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