class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        // Sort pairs based on the second element
        sort(pairs.begin(), pairs.end(),
            [](const vector<int> &a, const vector<int> &b) {
                return a[1] < b[1];
            }
        );

        vector<int> dp(n, 1);  // dp[i] will store the length of the longest chain ending with the i-th pair
        int longestChain = 1;

        for (int index = 1; index < n; index++) {
            for (int prevIndex = 0; prevIndex < index; prevIndex++) {
                // Check if pairs[prevIndex] can chain to pairs[index]
                if (pairs[prevIndex][1] < pairs[index][0]) {
                    dp[index] = max(dp[index], 1 + dp[prevIndex]);
                }
            }
            longestChain = max(longestChain, dp[index]);
        }

        return longestChain;
    }
};
