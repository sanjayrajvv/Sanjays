class Solution {
public:
    double myPow(double x, int n) {
    long exponent = abs(n);
        double ans = 1.0;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                ans = ans * x;
                exponent = exponent - 1;
            } else {
                exponent = exponent / 2;
                x = x * x;
            }
        }

        if (n < 0) {
            return 1.0 / ans;
        }

        return ans;
    }
};