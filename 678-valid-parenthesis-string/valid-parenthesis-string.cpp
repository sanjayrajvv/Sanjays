class Solution {
private:
    bool f(int index, int count, string s, vector<vector<int>> &dp) {
        if (count < 0) {
            return false;
        }

        if (index == s.size()) {
            return count == 0;
        }

        if (dp[index][count] != -1) return dp[index][count];

        bool result = false;
        if (s[index] == '(') {
            result =  f(index + 1, count + 1, s, dp);
        } else if (s[index] == ')') {
            result =  f(index + 1, count - 1, s, dp);
        } else {
            result = f(index + 1, count + 1, s, dp) || 
            f(index + 1, count - 1, s, dp) || 
            f(index + 1, count, s, dp); 
        }

        return dp[index][count] = result;
    }
public:
    bool checkValidString(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return f(0, 0, s, dp);
    }
};