class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        if (n < 3) return 0;

        unordered_set<string> uniquePalindromes;
        vector<int> left(26, -1), right(26, -1);

        for (int i = 0; i < n; ++i) {
            if (left[s[i] - 'a'] == -1) {
                left[s[i] - 'a'] = i;
            }

            right[s[i] - 'a'] = i;
        }

        for (int j = 1; j < n - 1; ++j) {
            for (char c = 'a'; c <= 'z'; ++c) {
                int i = left[c - 'a'], k = right[c - 'a'];

                if (i != -1 && k != -1 && i < j && j < k) {
                    string palindrome = {c, s[j], c};
                    uniquePalindromes.insert(palindrome);
                }
            }
        }

        return uniquePalindromes.size();
    }
};