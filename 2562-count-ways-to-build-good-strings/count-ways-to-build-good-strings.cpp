#include <vector>
using namespace std;

class Solution {
private:
    const int MOD = 1000000007;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> memo(high + 1, 0);
        memo[0] = 1;  // There's one way to construct a string of length 0, the empty string

        for (int i = 1; i <= high; i++) {
            if (i >= zero) {
                memo[i] = (memo[i] + memo[i - zero]) % MOD;
            }
            if (i >= one) {
                memo[i] = (memo[i] + memo[i - one]) % MOD;
            }
        }

        int result = 0;
        for (int i = low; i <= high; i++) {
            result = (result + memo[i]) % MOD;
        }

        return result;
    }
};
