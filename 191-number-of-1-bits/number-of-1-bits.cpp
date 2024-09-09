class Solution {
public:
    int hammingWeight(int n) {
        int hammingWeight = 0;

        while (n != 0) {
            hammingWeight++;
            
            n = n & (n - 1);
        }

        return hammingWeight;
    }
};