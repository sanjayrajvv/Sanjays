class Solution {
public:
    int numTrees(int n) {
        return nCr(2 * n, n) / (n + 1);
    }

private:
    long long nCr(int n, int r) {
        if (r > n - r) 
            r = n - r; // because nCr = nC(n-r)
        
        long long result = 1;
        
        for (int i = 0; i < r; ++i) {
            result *= (n - i);
            result /= (i + 1);
        }
        
        return result;
    }
};