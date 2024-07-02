class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mp;

        int m = ransomNote.size(), n = magazine.size();

        for (int i = 0; i < m || i < n; i++) {
            if (i < n) {
                mp[magazine[i]]++;
            }

            if (i < m) {
                mp[ransomNote[i]]--;
            }
        }

        for (auto it : mp) {
            if (it.second < 0) return false;
        }

        return true;
    }
};