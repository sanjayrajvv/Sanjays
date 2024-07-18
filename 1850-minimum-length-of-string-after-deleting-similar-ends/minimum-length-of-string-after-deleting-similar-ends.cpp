class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j]) break;

            while (i + 1 < j && s[i] == s[i + 1]) {
                i++;
            }
            i++;
            while (j - 1 > i && s[j] == s[j - 1]) {
                j--;
            }
            j--;
        }

        return j - i + 1;
    }
};