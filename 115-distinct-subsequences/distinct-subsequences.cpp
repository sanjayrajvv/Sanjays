class Solution {
public:
    int numDistinct(string s, string t) {
        int s_size = s.size(), t_size = t.size();

        vector<double> prev(t_size + 1, 0);
        vector<double> curr(t_size + 1, 0);
        prev[0] = 1; curr[0] = 1;

        for (int i = 1; i <= s_size; i++) {
            for (int j = 1; j <= t_size; j++) { 
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j - 1] + prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return (int)prev[t_size];
    }
};