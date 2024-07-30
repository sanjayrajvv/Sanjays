class Solution {
private:
    long long f(int i, vector<vector<int>>& questions, vector<long long> &dp) {
        int n = questions.size();
        if (i >= n) return 0;

        if (dp[i] != -1) return dp[i];

        long long notPick = f(i + 1, questions, dp);
        long long pick = questions[i][0] + f(i + questions[i][1] + 1, questions, dp);

        return dp[i] = max(pick, notPick);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();

        vector<long long> dp(n, -1);

        return f(0, questions, dp);
    }
};