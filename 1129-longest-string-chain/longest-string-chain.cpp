class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        vector<int> dp(n, 1);
        int longest = 1;

        for (int index = 0; index < n; index++) {
            for (int prevIndex = 0; prevIndex < index; prevIndex++) {
                if (isPredecessor(words[index], words[prevIndex])) {
                    dp[index] = max(dp[index], 1 + dp[prevIndex]);
                }
            }
            longest = max(longest, dp[index]);
        }

        return longest;
    }

private:
    bool isPredecessor(string longer, string shorter) {
        if (longer.size() != 1 + shorter.size()) return false;

        int i = longer.size() - 1, j = shorter.size() - 1;

        while (i >= 0) {
            if (j >= 0 && longer[i] == shorter[j]) {
                i--;
                j--;
            } else {
                i--;
            }
        }

        return j < 0;
    }
};