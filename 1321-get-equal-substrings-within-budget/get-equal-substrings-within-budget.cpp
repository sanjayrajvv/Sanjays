class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();

        int l = 0, maxLength = 0;
        int cost = 0;

        for (int r = 0; r < n; r++) {
            cost += abs((int(s[r]) - int(t[r])));

            while (cost > maxCost && l <= r) {
                cost -= abs((int(s[l]) - int(t[l])));
                l++;
            }

            if (cost <= maxCost) {
                maxLength = max(maxLength, r - l + 1);
            }
        }

        return maxLength;
    }
};