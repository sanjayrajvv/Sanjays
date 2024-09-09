class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xXor = 0;
        for (int i = 0; i < nums.size(); i++) {
            xXor ^= nums[i];
        }

        int rightMost = xXor & -xXor; //(xXor & xXor - 1) & xXor;
        int bucket1 = 0, bucket2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & rightMost) {
                bucket1 ^= nums[i];
            } else {
                bucket2 ^= nums[i];
            }
        }

        return {bucket1, bucket2};
    }
};