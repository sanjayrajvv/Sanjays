#include <cmath>
#include <climits>

class Solution {
    double f(double x, long long n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        
        double ans = f(x, n / 2);

        if (n % 2 == 1) {
            return x * ans * ans;
        } else {
            return ans * ans;
        }
    }
public:
    double myPow(double x, int n) {
        // Handle special case when n is INT_MIN
        long long N = n;
        double ans = f(x, abs(N));

        if (n < 0) return 1 / ans;
        else return ans;
    }
};
