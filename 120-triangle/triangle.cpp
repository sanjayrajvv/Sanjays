class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> next(n, 0);
        for (int i = 0; i < n; i++) next[i] = triangle[n - 1][i];

        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr(n, 0);
            for (int j = i; j >= 0; j--) {
                int down = (i + 1 > n) ? INT_MAX : next[j];
                int diag = (i + 1 > n && j + 1 > n) ? INT_MAX :
                next[j + 1];

                curr[j] = triangle[i][j] + min(down, diag);
            }

            next = curr;
        } 

        return next[0];
    }
};