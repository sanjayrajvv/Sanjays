class Solution {
private:
    static bool comp(vector<int> &p1, vector<int> &p2) {
        return p1[1] < p2[1];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        int longestChain = 1;

        sort(pairs.begin(), pairs.end(), comp);

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