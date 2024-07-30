class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> preCountB(n, 0);
        vector<int> postCountA(n, 0);

        for (int i = 1; i < n; i++) {
            //for 'b's
            if (s[i - 1] == 'b') {
                preCountB[i] = 1 + preCountB[i - 1];
            } else {
                preCountB[i] = preCountB[i - 1];
            }
        }

        for (int i =  n - 2; i >= 0; i--) {
            //for 'a's
            if (s[i + 1] == 'a') {
                postCountA[i] = 1 + postCountA[i + 1];
            } else {
                postCountA[i] = postCountA[i + 1];
            }
        }

        int minDeletions = INT_MAX;
        for (int i = 0; i < s.size(); i++) {
            minDeletions = min(minDeletions, preCountB[i] + postCountA[i]);
        }

        return minDeletions;
    }
};

//Use prefix sum to precompute the number of 'b's bfore an index and 'a's after it
//find the minimum of all index