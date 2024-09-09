class Solution {
public:
    int hammingWeight(int n) {
        int hammingWeight = 0;

        while (n != 0) {
            int bit = n & 1;
            if (bit) {
                hammingWeight++;
            }
            n >>= 1;
        }

        return hammingWeight;
    }
};