class Solution {
public:
    bool isMatch(string s, string p) {
        int sz = s.size(), pz = p.size();

        vector<bool> prev(pz + 1, 0);
        vector<bool> curr(pz + 1, 0);

        prev[0] = true;
        for (int j = 1; j <= pz; j++) {
            bool flag = true;
            for (int jj = 1; jj <= j; jj++) {
                if (p[jj - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for (int i = 1; i <= sz; i++) {
            for (int j = 1; j <= pz; j++) {
                bool match = false;
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    match = prev[j - 1];
                } 
                if (p[j - 1] == '*') {
                    match = prev[j] | curr[j - 1];
                } 
                curr[j] = match;
            }
            prev = curr;
        }

        return prev[pz];
    }
};