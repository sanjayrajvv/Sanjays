class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> prev(n, 0), curr(n, 0);

        for (int j = 0; j < n; j++) {
            prev[j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int leftDiag = (j - 1 >= 0) ? prev[j - 1] : INT_MAX;
                int up = prev[j];
                int rightDiag = (j + 1 < n) ? prev[j + 1] : INT_MAX;

                curr[j] = matrix[i][j] + min({leftDiag, up, rightDiag});
            }
            prev = curr;
        }

        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            mini = min(prev[i], mini);
        }

        return mini;
    }
};