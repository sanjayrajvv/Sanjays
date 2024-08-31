class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int numLessOrEqualToGoal = countSubarrays(nums, goal);
        int numLessThanGoal = countSubarrays(nums, goal - 1);

        return numLessOrEqualToGoal - numLessThanGoal;
    }

private:
    int countSubarrays(vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int n = nums.size();

        int totalCount = 0;
        int l = 0, sum = 0;
        for (int r = 0; r < n; r++) {
            sum += nums[r];

            while (sum > goal) {
                sum -= nums[l];
                l++;
            }

            if (sum <= goal) {
                totalCount += (r - l + 1);
            }
        }

        return totalCount;
    }
};