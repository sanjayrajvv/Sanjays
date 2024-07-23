class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        int longestChain = 1;

        sort(pairs.begin(), pairs.end(), 
        [](const vector<int> &a, const vector<int> &b) {
                return a[1] < b[1];
        });

        int i = 0, j = 1;
        while (j < n) {
            if (pairs[i][1] < pairs[j][0]) {
                longestChain++;
                i = j;
                j++;
            } else {
                j++;
            }
        }

        return longestChain;
    }
};