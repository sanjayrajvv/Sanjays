class Solution {
public:
    int countSubstrings(string s, string t) {
        int result = 0;
        int n1 = s.size(), n2 = t.size();

        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < t.size(); j++) {
                result += countHelper(i, j, s, t, 0);
            }
        }

        return result;
    }

private:
    int countHelper(int i, int j, string s, string t, int diffCount) {
        if (i >= s.size() || j >= t.size()) return 0;
        if (diffCount > 1) return 0;

        int result = 0;

        if (s[i] != t[j]) {
            diffCount++;
        } 

        if (diffCount == 1) {
            result += 1;
        }

        result += countHelper(i + 1, j + 1, s, t, diffCount);
        return result;
    }
};