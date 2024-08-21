class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        int n = s.size();
        
        // Memoization to store the results for subproblems
        vector<int> dp(n + 1, -1);
        
        return f(n, s, words, dp);
    }

private:
    bool f(int i, string s, unordered_set<string>& words, vector<int>& dp) {
        if (i == 0) return true;  // Empty string can always be segmented
        
        if (dp[i] != -1) return dp[i];
        
        for (int index = i - 1; index >= 0; index--) {
            string word = s.substr(index, i - index);
            if (words.find(word) != words.end()) {
                if (f(index, s, words, dp)) {
                    return dp[i] = true;
                }
            }
        }

        return dp[i] = false;
    }
};
