class Solution {
    long long hoursTook(vector<int> &piles, int k) {
        long long hoursTaken = 0;
        for (int i = 0; i < piles.size(); i++) {
            hoursTaken += (piles[i] - 1) / k + 1;
        }

        return hoursTaken;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        if (piles.size() == h) return high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (hoursTook(piles, mid) <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};