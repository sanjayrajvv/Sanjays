#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    const int total = 115;
    const int a = 75, b = 10;
    
    bool canWin(int x, int y, vector<vector<int>>& dp) {
        if (x < 0 || y < 0) return false;
        if (dp[x][y] != -1) return dp[x][y];

        // Try all combinations of i and j to see if the current player can force a win
        for (int i = 0; i <= x; ++i) {
            for (int j = 0; j <= y; ++j) {
                if (a * i + b * j == total && !canWin(x - i, y - j, dp)) {
                    return dp[x][y] = true;
                }
            }
        }

        return dp[x][y] = false;
    }
    
public:
    string losingPlayer(int x, int y) {
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));
        return canWin(x, y, dp) ? "Alice" : "Bob";
    }
};
