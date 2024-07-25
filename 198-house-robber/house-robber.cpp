class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 0);
        int dp1 = nums[0];
        int dp2 = 0;

        for (int index = 1; index < n; index++) {
            int pick = nums[index]; if (index > 1) pick += dp2;
            int notPick = dp1;

            int curr = max(pick, notPick);

            dp2 = dp1;
            dp1 = curr;
        }

        return dp1;
    }
};