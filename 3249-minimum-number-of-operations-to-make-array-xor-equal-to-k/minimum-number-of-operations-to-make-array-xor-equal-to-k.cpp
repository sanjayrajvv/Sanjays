class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;

        for (int bit = 0; bit < 32; bit++) {
            int bitCount = 0;
            for (int i = 0; i < n; i++) {
                if(nums[i] & (1 << bit)) {
                    bitCount++;
                }
            }

            bool kBitSet = k & (1 << bit);
            if (kBitSet && bitCount % 2 == 0) {
                flips++;
            } else if (!kBitSet && bitCount % 2) {
                flips++;
            }
        }

        return flips;
    }
};