class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();

        if (m > n) {
            return false;
        }

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        for (int i = 0; i < m; i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int matchCount = 0;
        for (int i = 0; i < 26; i++) {
            if (s1Count[i] == s2Count[i]) {
                matchCount++;
            }
        }

        for (int i = m; i < n; i++) {
            if (matchCount == 26) {
                return true;
            }

            int index = s2[i] - 'a';
            s2Count[index]++;
            if (s1Count[index] == s2Count[index]) {
                matchCount++;
            } else if (s1Count[index] + 1 == s2Count[index]) {
                matchCount--;
            }

            index = s2[i - m] - 'a';
            s2Count[index]--;
            if (s1Count[index] == s2Count[index]) {
                matchCount++;
            } else if (s1Count[index] - 1 == s2Count[index]) {
                matchCount--;
            }
        }

        return matchCount == 26;
    }
};