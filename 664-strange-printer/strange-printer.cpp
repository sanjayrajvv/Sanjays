class Solution {
public:
    int strangePrinter(string s) {
        s = removeDuplicates(s);

        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int start = n - 1; start >= 0; start--) {
            for (int end = 0; end < n; end++) {
                if (start > end) continue;

                int minTurns = 1 + dp[start + 1][end];
                for (int k = start + 1; k <= end; k++) {
                    if (s[start] == s[k]) {
                        int turnsWithMatch = dp[start][k - 1] + dp[k + 1][end];
                        minTurns = min(minTurns, turnsWithMatch);
                    }
                }

                dp[start][end] = minTurns;
            }
        }

        return dp[0][n - 1];
    }

private:  
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