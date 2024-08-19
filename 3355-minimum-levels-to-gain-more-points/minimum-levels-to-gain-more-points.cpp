class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();

        // Prefix and Suffix sums
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);

        // Initializing prefix and suffix
        prefix[0] = (possible[0] == 1) ? 1 : -1;
        suffix[n - 1] = (possible[n - 1] == 1) ? 1 : -1;

        // Calculate prefix sums
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + (possible[i] == 1 ? 1 : -1);
        }

        // Calculate suffix sums
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + (possible[i] == 1 ? 1 : -1);
        }

        // Find the minimum index where prefix > suffix
        for (int i = 0; i < n - 1; i++) {
            if (prefix[i] > suffix[i + 1]) {
                return i + 1;
            }
        }

        return -1;
    }
};
