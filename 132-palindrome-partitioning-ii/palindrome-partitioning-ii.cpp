class Solution {
    bool isPalindrome(int i, int j, string &s, vector<vector<int>> &dp2) {
        if (dp2[i][j] != -1) return dp2[i][j];
        
        int start = i, end = j;
        while (start < end) {
            if (s[start] != s[end]) return dp2[i][j] = false;
            start++;
            end--;
        }

        return dp2[i][j] = true;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        vector<vector<int>> dp2(n, vector<int>(n, -1));

        for (int i = n - 1; i >= 0; i--) {
            int minCost = INT_MAX;
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, s, dp2)) {
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }

        return dp[0] - 1;
    }
};
