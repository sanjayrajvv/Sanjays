class Solution {
public:
    int fib(int n) {
        vector<int> dp(n + 1, 0);
        if (n == 0) return 0;
        int prev1 = 0; 
        int prev2 = 1;

        int curr;
        for (int i = 2; i <= n; i++) {
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
};