class Solution {
private:
    int mod = 1e9 + 7;
private:
    int f(int n, vector<int> &dp) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;

        if (dp[n] != -1) return dp[n];

        return dp[n] = (2 * f(n - 1, dp) % mod + f(n - 3, dp) % mod) % mod;
    }
public:
    int numTilings(int n) {
        vector<int> dp(n + 1, -1);

        return f(n, dp);
    }
};