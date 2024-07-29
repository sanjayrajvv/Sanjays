class Solution {
private:
    int f(int i, string s, vector<string>& wordDict, vector<int> &dp) {
        if (i < 0) return true;

        if (dp[i] != -1) return dp[i];

        for (int index = i; index >= 0; index--) {
            string word = s.substr(index, i - index + 1);
            if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
                if (f(index - 1, s, wordDict, dp)) {
                    return true;
                }
            }
        }

        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<int> dp(n, -1);

        return f(n - 1, s, wordDict, dp);
    }
};