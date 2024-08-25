class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long len = 0;

        long long ans = 0;

        int i = 0;
        while (i < n) {
            if (nums[i] == 0) {
                len++;
            } else {
                ans += (len * (len + 1)) / 2;
                len = 0;
            }
            i++;
        }
        if (len > 0) ans += (len * (len + 1)) / 2;

        return ans;
    }
};