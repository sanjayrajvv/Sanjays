class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        if (n < 3) return false;

        int  i = 0, j = 1, k = 2;
        int firstSmall = INT_MAX, secondSmall = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (nums[i] <= firstSmall) {
                firstSmall = nums[i];
            } else if (nums[i] <= secondSmall) {
                secondSmall = nums[i];
            } else return true;
        }

        return false;
    }
};