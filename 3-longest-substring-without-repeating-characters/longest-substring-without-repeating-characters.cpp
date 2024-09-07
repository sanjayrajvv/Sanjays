class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256, -1);

        int maxLen = 0;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            //repeating element encountered
            //So change the left pointer
            if (mp[s[r]] != -1) {
                l = max(l, mp[s[r]] + 1);
            }

            cout << l << " " << r << endl; 

            mp[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};