class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        int ans = 0;
        for (auto &pair : mp) {
            ans += (pair.second % 2 == 0) ? 2 : 1;
        }

        return ans;
    }
};