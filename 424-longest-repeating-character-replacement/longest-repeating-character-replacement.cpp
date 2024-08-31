class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int maxFrequency = 0, maxLen = 0;
        vector<int> h(26, 0);

        int l = 0;
        for (int r = 0; r < n; r++) {
            h[s[r] - 'A']++;
            maxFrequency = max(maxFrequency, h[s[r] - 'A']);

            if ((r - l + 1) - maxFrequency > k) {
                h[s[l] - 'A']--;
                l++;

                maxFrequency = 0;
                for (int i = 0; i < 26; i++) {
                    maxFrequency = max(maxFrequency, h[i]);
                }
            }

            if ((r - l + 1) - maxFrequency <= k) {
                maxLen = max(maxLen, r - l + 1);
            }
        }

        return maxLen;
    }
};