class Solution {
public:
    int arrangeCoins(int n) {
        int l = 1, h = n;

        while (l <= h) {
            long long mid = l + (h - l) / 2;
            long long sum = mid * (mid + 1) / 2;

            if (sum == n) {
                return (int)mid;
            } else if (sum > n) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return h;
    }
};