class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;           // Stores all possible palindrome partitions
        vector<string> ds;                    // Stores the current partition
        vector<vector<bool>> dp(n, vector<bool>(n, false));  // DP table to store palindromic substrings
        
        // Fill the DP table
        fill_dp_table(s, dp);
        
        // Start backtracking
        backtrack(0, s, ds, ans, dp);

        return ans;                           // Return the result
    }

private:
    // Function to fill the DP table for palindromic checks
    void fill_dp_table(const string& s, vector<vector<bool>>& dp) {
        int n = s.size();
        
        // Every single character is a palindrome
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        // Fill the DP table for substrings of length 2 and more
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;  // j is the endpoint of the substring starting at i
                
                if (s[i] == s[j]) {
                    if (length == 2) {
                        dp[i][j] = true;  // Two-character substrings
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];  // Longer substrings
                    }
                }
            }
        }
    }

    // Backtracking function to explore all partitions
    void backtrack(int index, const string& s, vector<string>& ds, vector<vector<string>>& ans, const vector<vector<bool>>& dp) {
        if (index == s.size()) {
            ans.push_back(ds);  // Store the partition when we reach the end of the string
            return;
        }

        for (int i = index; i < s.size(); i++) {
            // Use the precomputed DP table to check if the substring is a palindrome
            if (dp[index][i]) {
                ds.push_back(s.substr(index, i - index + 1));  // Add the substring to the current partition
                backtrack(i + 1, s, ds, ans, dp);              // Continue exploring the remaining string
                ds.pop_back();                                 // Backtrack (remove the last added substring)
            }
        }
    }
};
