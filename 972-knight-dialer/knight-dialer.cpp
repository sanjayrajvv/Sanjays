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
    
public:
    int knightDialer(int n) {
        dp = vector(n + 1, vector<int>(10, 0));
        for (int i = 0; i < 10; i++) dp[0][i] = 1;

        for (int rem = 1; rem < n; rem++) {
            for (int square = 0; square < 10; square++) {
                int ans = 0;
                for (int nextSquare : jumps[square]) {
                    ans = (ans + dp[rem - 1][nextSquare]) % MOD;
                }

                dp[rem][square] = ans;
            }
        }

        int ans = 0;
        for (int square = 0; square < 10; square++) {
            ans = (ans + dp[n - 1][square]) % MOD;
        }

        return ans;
    }
};