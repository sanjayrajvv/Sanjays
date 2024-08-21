class Solution {
public:
    int strangePrinter(string s) {
        s = removeDuplicates(s);

        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return minimumTurns(0, n - 1, s, dp);
    }

private:
    int minimumTurns(int start, int end, string s, vector<vector<int>>& dp) {
        if (start > end) {
            return 0;
        }

        if (dp[start][end] != -1) {
            return dp[start][end];
        }

        int minTurns = 1 + minimumTurns(start + 1, end, s, dp);
        for (int k = start + 1; k <= end; k++) {
            if (s[start] == s[k]) {
                int turnsWithMatch = minimumTurns(start, k - 1, s, dp) + 
                                     minimumTurns(k + 1, end, s, dp);
                minTurns = min(minTurns, turnsWithMatch);
            }
        }

        dp[start][end] = minTurns;
        return dp[start][end];
    }

    string removeDuplicates(string s) {
        string unique = "";

        int i = 0;
        while (i < s.size()) {
            char currentChar = s[i];
            unique += currentChar;

            while (i < s.size() && s[i] == currentChar) {
                i++;
            }
        }

        return unique;
    }
};