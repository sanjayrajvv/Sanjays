class Solution {
public:
    int longestIdealString(const string &s, int k) {
        int n = s.size();
        vector<int> dp(26, 0); // We need only 26 elements for 'a' to 'z'

        for (int i = 0; i < n; ++i) {
            int currCharIndex = s[i] - 'a';
            int maxLen = 0;

            // Find the maximum length of all valid previous characters
            for (int j = max(0, currCharIndex - k); j <= min(25, currCharIndex + k); ++j) {
                maxLen = max(maxLen, dp[j]);
            }

            // Update the dp array for the current character
            dp[currCharIndex] = maxLen + 1;
        }

        // Find the maximum value in the dp array, which represents the length of the longest ideal string
        return *max_element(dp.begin(), dp.end());
    }
};
