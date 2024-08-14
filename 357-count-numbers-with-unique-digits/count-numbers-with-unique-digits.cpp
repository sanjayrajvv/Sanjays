class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int fact[10] = {1};

        for (int i = 1; i < 10; i++) {
            fact[i] = i * fact[i - 1];
        }

        int total = 1;

        for (int k = 1; k <= n; k++) {
            total += 9 * fact[9] / fact[10 - k];
        }

        return total;
    }
};