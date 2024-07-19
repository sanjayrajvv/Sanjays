class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> luckyNumbers;
        set<int> st;

        for (int i = 0; i < m; i++) {
            int mini = INT_MAX;
            for (int j = 0; j < n; j++) {
                mini = min(mini, matrix[i][j]);
            }
            st.insert(mini);
        }

        for (int i = 0; i < n; i++) {
            int maxi = 0;
            for (int j = 0; j < m; j++) {
                maxi = max(maxi, matrix[j][i]);
            }
            if (st.find(maxi) != st.end()) {
                luckyNumbers.push_back(maxi);
            }
        }

        return luckyNumbers;
    }
};