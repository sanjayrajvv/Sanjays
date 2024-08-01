class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int m = left, n = right;

        int shift = 0;
        while (m != n) {
            m = m >> 1; n = n >> 1;

            shift++;
        }

        return (n << shift);
    }
};