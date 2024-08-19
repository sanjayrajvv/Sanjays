#define vi vector<int>

class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;

        vector<vi> dp(n, vi(n, -1));

        return 1 + count(1, 1, n, dp);
    }

private:
    int count(int i, int l, int n, vector<vi>& dp) {
        if (i > n) return 1e9;

        if (i == n) return 0;

        if (dp[i][l] != -1) return dp[i][l];

        int copyPaste = 2 + count(i + i, i, n, dp);
        int paste = 1 + count(i + l, l, n, dp);

        return dp[i][l] = min(copyPaste, paste);
    }
};