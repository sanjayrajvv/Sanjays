class Solution {
private:
    int f(int i, int m, int n, vector<string> &strs, vector<vector<vector<int>>> &dp) {
        if (i < 0) {
            return 0;
        }

        if (dp[i][m][n] != -1) {
            return dp[i][m][n];
        }

        int zeros = count(strs[i].begin(), strs[i].end(), '0');
        int ones = strs[i].size() - zeros;

        int notTake = f(i - 1, m, n, strs, dp);
        int take = INT_MIN;
        if (m >= zeros && n >= ones) {
            take = 1 + f(i - 1, m - zeros, n - ones, strs, dp);
        }

        return dp[i][m][n] = max(notTake, take);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();

        vector<vector<vector<int>>> dp(size, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        return f(size - 1, m, n, strs, dp);
    }
};
