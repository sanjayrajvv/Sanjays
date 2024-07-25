class Solution {
public:
    int numSquares(int n) {
        if (n == 1) return 1;

        vector<int> squares;
        for (int i = 1; i * i <= n; ++i) {
            squares.push_back(i * i);
        }

        vector<int> dp(n + 1, 0);
        for (int target = 1; target <= n; target++) {
            int mini = INT_MAX;
            for (int s : squares) {
                if (target >= s) {
                    mini = min(mini, 1 + dp[target - s]);
                }
            }

            dp[target] = mini;
        }

        return dp[n];
    }
};