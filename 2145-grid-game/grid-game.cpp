class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topSum = 0, bottomSum = 0, result = LONG_MAX;

        for (int i = 0; i < grid[0].size(); i++) topSum += grid[0][i];

        for (int i = 0; i < grid[0].size(); i++) {
            topSum -= grid[0][i];

            result = min(result, max(topSum, bottomSum));

            bottomSum += grid[1][i];
        }

        return result;
    }
};