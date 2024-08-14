class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();

        vector<int> curr(3, INT_MIN);
        curr[0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            vector<int> next(curr);
            for (int remainder = 0; remainder < 3; remainder++) {
                int take = nums[i] + next[(remainder + nums[i]) % 3];
                int notTake = next[remainder];

                curr[remainder] = max(take, notTake);
            }
            next = curr;
        }

        return curr[0];
    }
};