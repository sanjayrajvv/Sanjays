class Solution {
public:
    int hammingWeight(int n) {
        int countOfOnes = 0;
        for (int i = 0; i < 32; i++) {
            countOfOnes += (n >> i) & 1;
        }

        return countOfOnes;
    }
};