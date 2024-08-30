class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;

        int minElement = INT_MAX;

        while (l <= h) {
            //if (nums[l] < nums[h]) return nums[l];

            int mid = l + (h - l) / 2;
            if (nums[l] <= nums[mid]) {
                minElement = min(minElement, nums[l]);
                l = mid + 1;
            } else {
                minElement = min(minElement, nums[mid]);
                h = mid - 1;
            }
        }

        return minElement;
    }
};