class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int reverse = 0;
        for (int i = 1; i <= 32; i++) {
            reverse <<= 1;
            int lastBit = n & 1;
            reverse |= lastBit;
            n >>= 1;
        }

        return reverse;
    }
};