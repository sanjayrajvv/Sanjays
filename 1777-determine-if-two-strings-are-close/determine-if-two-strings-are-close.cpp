class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> count1(26, 0), count2(26, 0);
        vector<bool> exist1(26, false), exist2(26, false);

        for (char c : word1) {
            count1[c - 'a']++;
            exist1[c - 'a'] = true;
        }
        for (char c : word2) {
            count2[c - 'a']++;
            exist2[c - 'a'] = true;
        }

        for (int i = 0; i < 26; ++i) {
            if (exist1[i] != exist2[i]) return false;
        }

        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());

        return count1 == count2;
    }
};