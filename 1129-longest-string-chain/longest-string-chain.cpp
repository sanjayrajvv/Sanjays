class Solution {
    bool checkPossible(string word1, string word2) {
        if (word1.size() != word2.size() + 1) return false;

        int first = 0;
        int second = 0;
        while (first < word1.size()) {
            if (second < word2.size() && word1[first] == word2[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }

        if (first == word1.size() && second == word2.size()) return true;
        else return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);

        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        int len = INT_MIN;
        for (int index = 0; index < n; index++) {
            for (int prev_index = 0; prev_index < index; prev_index++) {
                if (checkPossible(words[index], words[prev_index]) && 1 + dp[prev_index] > dp[index]) {
                    dp[index] = 1 + dp[prev_index];
                }
            }

            len = max(len, dp[index]);
        }

        return len;
    }
};