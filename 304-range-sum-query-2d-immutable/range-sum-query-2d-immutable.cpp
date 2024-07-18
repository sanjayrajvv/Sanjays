class NumMatrix {
    vector<vector<int>> matrix;
    vector<vector<int>> prefixMatrix;
    int m, n;
public:
    NumMatrix(vector<vector<int>>& matrix) : matrix(matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            m = 0;
            n = 0;
            return;
        }
        
        m = matrix.size();
        n = matrix[0].size();
        
        // Initialize prefixMatrix with zeros
        prefixMatrix = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        
        // Compute prefix sums
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixMatrix[i][j] = matrix[i - 1][j - 1]
                                    + prefixMatrix[i - 1][j]
                                    + prefixMatrix[i][j - 1]
                                    - prefixMatrix[i - 1][j - 1];
            }
        }
    }

    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (m == 0 || n == 0) return 0;
        
        // Convert 1-based index to 0-based
        row1++;
        col1++;
        row2++;
        col2++;
        
        // Calculate the sum using prefix sums
        int sum = prefixMatrix[row2][col2]
                - prefixMatrix[row1 - 1][col2]
                - prefixMatrix[row2][col1 - 1]
                + prefixMatrix[row1 - 1][col1 - 1];
        
        return sum;
    }

};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
