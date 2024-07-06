class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int l = 0, h = (m * n) - 1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return false;
    }
};