class Solution {
public:
    int minFlips(int a, int b, int c) {
        int minFlip = 0;
        for (int i = 0; i < 32; i++) {
            bool lastBitof_a = (a >> i) & 1;
            bool lastBitof_b = (b >> i) & 1;
            bool lastBitof_c = (c >> i) & 1;

            if (lastBitof_c == 1) {
                if (lastBitof_a == 0 && lastBitof_b == 0) {
                    minFlip++;
                }
            } else {
                if (lastBitof_a == 1 && lastBitof_b == 1) {
                    minFlip += 2;
                } else if (lastBitof_a != lastBitof_b) {
                    minFlip++;
                }
            }
        }

        return minFlip;
    }
};