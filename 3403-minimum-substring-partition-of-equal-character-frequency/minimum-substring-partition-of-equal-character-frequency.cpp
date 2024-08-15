class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.size();

        vector<int> dp(n, -1);

        return f(0, s, dp);
    }

private:
    int f(int index, string s, vector<int>& dp) {
        if (index == s.size()) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        unordered_map<char, int> mp;
        int ans = 1e9;
        for (int i = index; i < s.size(); i++) {
            mp[s[i]]++;
            if (balanced(mp)) {
                int res = f(i + 1, s, dp);
                if (res != -1) {
                    ans = min(ans, res + 1);
                }
            }
        }

        return dp[index] = ans == 1e9 ? -1 : ans;
    }

    bool balanced(unordered_map<char, int>& mp) {
        int freq = -1;

        for (auto pair : mp) {
            if (freq == -1) {
                freq = pair.second;  // Set the frequency for comparison
            } else if (freq != pair.second) {
                return false;  // If any frequency is different, return false
            }
        }

        return true;  // All frequencies are the same
    }
};