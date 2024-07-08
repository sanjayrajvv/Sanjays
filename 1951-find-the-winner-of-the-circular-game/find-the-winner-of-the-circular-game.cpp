class Solution {
public:
    int findTheWinner(int n, int k) 
    {
        int winner = 0; // This represents the last person standing, 0-based index.
        for (int i = 1; i <= n; ++i) {
            winner = (winner + k) % i;
        }
        return winner + 1; // Convert to 1-based index.
    }
};
