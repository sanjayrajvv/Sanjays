class Solution {
private:
    const int MOD = 1000000007;

    int f(int i, int low, int high, int zero, int one, vector<int>& memo) {
        if (i > high) return 0;

        if (memo[i] != -1) return memo[i];

        int count = 0;
        if (i >= low && i <= high) count = 1;

        count = (count + f(i + zero, low, high, zero, one, memo) % MOD) % MOD;
        count = (count + f(i + one, low, high, zero, one, memo) % MOD) % MOD;

        memo[i] = count;
        return memo[i];
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> memo(high + 1, -1);
        return f(0, low, high, zero, one, memo);
    }
};
