class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xXor = 0;
        for (int i = 0; i < nums.size(); i++) {
            xXor ^= nums[i];
        }

        // Finding the rightmost set bit
        int rightMost = xXor & -xXor;

        int b1 = 0, b2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & rightMost) {
                b1 ^= nums[i];
            } else {
                b2 ^= nums[i];
            }
        }

        return {b1, b2};
    }
};
