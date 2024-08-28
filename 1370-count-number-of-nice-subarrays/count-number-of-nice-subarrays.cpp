class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       int countLessThanOrEqualToK = countSubarrays(nums, k);
       int countLessThanK = countSubarrays(nums, k - 1);

       return countLessThanOrEqualToK - countLessThanK;
    }

private:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int totalCount = 0;
        int l = 0, sum = 0;
        for (int r = 0; r < n; r++) {
            sum += (nums[r] % 2);

            while (sum > k) {
                sum -= (nums[l] % 2);
                l++;
            }
            totalCount += (r - l + 1);
        }

        return totalCount;
    }
};