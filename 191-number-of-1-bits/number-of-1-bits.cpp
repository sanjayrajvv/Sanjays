class Solution {
public:
    int hammingWeight(int n) {
        int hammingWeight = 0;

        for (int i = 31; i >= 0; i--) {
            hammingWeight += (n >> i) & 1;
        }

        return hammingWeight;
    }
};