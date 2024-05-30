class Solution {
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size(), l2 = text2.size();

        vector<int> prev(l2 + 1, 0), curr(l2 + 1, 0);

        for (int index1 = 1; index1 <= l1; index1++) {
            for (int index2 = 1; index2 <= l2; index2++) {

                if (text1[index1 - 1] == text2[index2 - 1]) {
                    curr[index2] = 1 + prev[index2 - 1];
                } else {
                    curr[index2] = max(prev[index2], curr[index2 - 1]);
                }
            }

            prev = curr;
        }

        return prev[l2];
    }
public:
    int minInsertions(string s) {
        string s2;
        for (int i = 0; i < s.size(); i++) s2.push_back(s[i]);
        reverse(s2.begin(), s2.end());

        return s.size() - longestCommonSubsequence(s, s2);
    }
};