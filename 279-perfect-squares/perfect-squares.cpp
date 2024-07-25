class Solution {
private:
    int f(int target, vector<int> &squares, vector<int> &dp) {
        if (target == 0) return 0;
        if (dp[target] != -1) return dp[target];

        int mini = INT_MAX;
        for (int s : squares) {
            if (target >= s) {
                mini = min(mini, 1 + f(target - s, squares, dp));
            }
        }

        return dp[target] = mini;
    }
public:
    int numSquares(int n) {
        if (n == 1) return 1;

        vector<int> squares;
        for (int i = 1; i * i <= n; ++i) {
            squares.push_back(i * i);
        }

        vector<int> dp(n + 1, -1);

        return f(n, squares, dp);
    }
};