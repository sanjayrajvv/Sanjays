class Solution {
public:
    int findComplement(int num) {
        // Start with a mask of 1
        unsigned int mask = ~0;

        // Shift the mask left until it just covers the number
        while (num & mask) {
            mask <<= 1;
        }

        // XOR num with the inverse of the mask to get the complement
        return ~mask & ~num;
    }
};
