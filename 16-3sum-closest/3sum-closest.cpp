class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int difference = INT_MAX;
        int closest;

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == target) return sum;

                if (abs(sum - target) < difference) {
                    difference = abs(sum - target);
                    closest = sum;
                }

                if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return closest;
    }
};