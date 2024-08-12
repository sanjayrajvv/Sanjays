class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>> memo(3, vector<int>(n + 1, -1));
        return getMinimumMoves(2, n, memo);
    }

private:
    int getMinimumMoves(int eggs, int floors, vector<vector<int>>& memo) {
        if (floors == 0) {
            return 0;
        }
        if (floors == 1) {
            return 1;
        }
        if (eggs == 1) {
            return floors;
        }
        if (memo[eggs][floors] != -1) {
            return memo[eggs][floors];
        }

        int minMoves = INT_MAX;

        for (int x = 1; x <= floors; ++x) {
            int worstCaseMoves = max(getMinimumMoves(eggs - 1, x - 1, memo), 
                                     getMinimumMoves(eggs, floors - x, memo));
            
            minMoves = min(minMoves, worstCaseMoves + 1);
        }

        memo[eggs][floors] = minMoves;
        return minMoves;
    }
};
