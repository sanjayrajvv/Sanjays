class Solution {
private:
    vector<vector<int>> dp;
    int MOD = 1e9 + 7;
    vector<vector<int>> jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };

    int f(int rem, int square) {
        if (rem == 0) {
            return 1;
        }

        if (dp[rem][square] != -1) {
            return dp[rem][square];
        }

        int ans = 0;
        for (int nextSquare : jumps[square]) {
            ans = (ans + f(rem - 1, nextSquare)) % MOD;
        }

        dp[rem][square] = ans;
        return ans;
    }
public:
    int knightDialer(int n) {
        dp = vector(n + 1, vector<int>(10, -1));
        int ans = 0;
        for (int square = 0; square < 10; square++) {
            ans = (ans + f(n - 1, square)) % MOD;
        }

        return ans;
    }
};