class Solution {
private:
    int f(int i, vector<vector<int>>& books, int n, int shelfWidth, vector<int> &dp) {
        if (i == n) {
            return 0;
        }

        if (dp[i] != -1) return dp[i];

        int currWidth = shelfWidth;
        int maxHeight = 0;
        int res = INT_MAX;
        for (int j = i; j < n; j++) {
            int width = books[j][0];
            int height = books[j][1];
            if (currWidth < width) {
                break;
            }
            currWidth -= width;
            maxHeight = max(maxHeight, height);
            res = min(res, maxHeight + f(j + 1, books, n, shelfWidth, dp));
        }

        return dp[i] = res;
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();

        vector<int> dp(n, -1);

        return f(0, books, n, shelfWidth, dp);
    }
};