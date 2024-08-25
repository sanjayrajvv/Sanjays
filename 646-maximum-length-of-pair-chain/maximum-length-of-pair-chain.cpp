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

        int longestChain = 1;
        int currEnd = pairs[0][1];

        for (int i = 1; i < n; i++) {
            if (currEnd < pairs[i][0]) {
                longestChain++;
                currEnd = pairs[i][1];
            }
        }

        return longestChain;
    }
};
