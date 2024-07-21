class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> mp;
        for (int i = 0; i < order.size(); i++) {
            mp[order[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

            bool isSorted = false;
            for (int j = 0; j < min(s1.size(), s2.size()); j++) {
                if (s1[j] != s2[j]) {
                    if (mp[s1[j]] > mp[s2[j]]) {
                        return false;
                    }
                    isSorted = true;
                    break;
                }
            }
            if (!isSorted && s1.size() > s2.size()) {
                return false;
            }
        }

        return true;
    }
};