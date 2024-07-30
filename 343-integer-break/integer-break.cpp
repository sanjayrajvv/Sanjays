class Solution {
private:
    // Memoization table to store results of subproblems
    vector<int> memo;
    
    int integerBreakRecursive(int n) {
        // Base case: when n is 1, return 1 as the product (although for the problem, we shouldn't actually use this)
        if (n == 1) return 1;

        // Check if result is already computed
        if (memo[n] != -1) return memo[n];

        int maxProduct = 0;
        // Try breaking the number into two parts: i and (n - i)
        for (int i = 1; i <= n / 2; ++i) {
            // maxProduct is the maximum of the current product and the new product obtained by splitting
            maxProduct = max(maxProduct, max(i * (n - i), i * integerBreakRecursive(n - i)));
        }

        // Store the result in the memo table and return
        memo[n] = maxProduct;
        return maxProduct;
    }

public:
    int integerBreak(int n) {
        // Initialize memo table with -1 to indicate uncomputed states
        memo = vector<int>(n + 1, -1);

        // Handle the base cases explicitly as per problem requirements
        if (n == 2) return 1;  // The integer 2 can only be broken into 1 + 1 which gives the product 1
        if (n == 3) return 2;  // The integer 3 can be broken into 1 + 2 which gives the product 2

        // Call the recursive function with memoization
        return integerBreakRecursive(n);
    }
};
