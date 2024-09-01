class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> newArray(m, vector<int>(n));

        if (m * n != original.size()) {
            return {};
        }

        int k = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (k < original.size())
                newArray[r][c] = original[k++];
            }
        }

        return newArray;
    }
};