class Solution {
private:
    int MOD = 1e9 + 7;

public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> dp(zero + 1, 
                        vector<vector<int>>(one + 1, vector<int>(3, -1)));
        return f(zero, one, -1, limit, dp);
    }

private:
    int f(int zero, int one, int last, int limit, vector<vector
    <vector<int>>>& dp) {
        if (zero < 0 || one < 0) {
            return 0;
        }
        if (zero == 0 && one == 0) {
            return 1;
        }

        if (dp[zero][one][last + 1] != -1) {
            return dp[zero][one][last + 1];
        }

        int count = 0;

        if (last == -1 || last == 1) {
            for (int p = 1; p <= min(limit, zero); p++) {
                count = (count + f(zero - p, one, 0, limit, dp)) % MOD;
            }
        }

        if (last == -1 || last == 0) {
            for (int p = 1; p <= min(limit, one); p++) {
                count = (count + f(zero, one - p, 1, limit, dp)) % MOD;
            }
        }

        return dp[zero][one][last + 1] = count;
    }
};