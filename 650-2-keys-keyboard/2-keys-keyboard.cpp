class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                while (n % i == 0) {
                    ans += i;
                    n /= i;
                }
            }
        }
        if (n > 1) {
            ans += n;  // Add the remaining prime factor if any
        }

        return ans;
    }
};