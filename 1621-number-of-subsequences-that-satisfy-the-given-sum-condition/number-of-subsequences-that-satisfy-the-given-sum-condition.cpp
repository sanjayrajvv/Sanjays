class Solution {
private:
    int mod = 1e9 + 7;
public:
    int numSubseq(vector<int>& nums, int target) {
        int  i = 0, j = 0, n = nums.size();
        int total = 0;
        sort(nums.begin(), nums.end());

        vector<int> powers(n, 1);
        for (int i = 1; i < n; i++) {
            powers[i] = (2 * powers[i - 1]) % mod;
        }

        int left = 0, right = n - 1;
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                total = (total + powers[right - left]) % mod;
                left++;
            } else {
                right--;
            }
        }

        return total;
    }
};