class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<long long> prevRow(n);
        for (int i = 0; i < n; i++) {
            prevRow[i] = points[0][i];
        }

        for (int row = 0; row < m - 1; ++row) {
            vector<long long> leftMax(n);
            vector<long long> rightMax(n);
            vector<long long> currRow(n);

            leftMax[0] = prevRow[0];
            for (int col = 1; col < n; ++col) {
                leftMax[col] = max(leftMax[col - 1] - 1, prevRow[col]);
            }

            rightMax[n - 1] = prevRow[n - 1];
            for (int col = n - 2; col >= 0; --col) {
                rightMax[col] = max(rightMax[col + 1] - 1, prevRow[col]);
            }

            for (int col = 0; col < n; col++) {
                currRow[col] = points[row + 1][col] + 
                                  max(leftMax[col], rightMax[col]);
            }

            prevRow = currRow;
        }

        long long maxPoints = 0;
        for (int col = 0; col < n; ++col) {
            maxPoints = max(maxPoints, prevRow[col]);
        }

        return maxPoints;
    }
};