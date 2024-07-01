class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, maxLen = 0;

        vector<int> mp(256, -1);

        while (r < s.size()) {
            if (mp[s[r]] != -1) {
                l = max(l, mp[s[r]] + 1);
            }

            mp[s[r]] = r;

            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};