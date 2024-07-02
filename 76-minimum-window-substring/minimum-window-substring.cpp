class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();

        vector<int> mp(256, 0);
        for (int i = 0; i < n; i++) {
            mp[t[i]]++;
        }

        int l = 0, r = 0, count = 0, si = -1, minLen = 1e9;
        while (r < m) {
            if (mp[s[r]] > 0) count++;
            mp[s[r]]--;

            while (count == n) {
                if ((r - l + 1) < minLen) {
                    minLen = r - l + 1;
                    si = l;
                }

                mp[s[l]]++;
                if (mp[s[l]] > 0) count--;
                l++;
            }

            r++;
        }

        return si == - 1 ? "" : s.substr(si, minLen);
    }
};