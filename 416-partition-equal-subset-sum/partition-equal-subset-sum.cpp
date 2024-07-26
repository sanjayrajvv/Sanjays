class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        int target = sum / 2;

        vector<bool> prev(target + 1, false);
        vector<bool> curr(target + 1, false);
        prev[0] = curr[0] = true;
        if (nums[0] <= target) prev[nums[0]] = true;

        for (int index = 1; index < n; index++) {
            for (int currTarget = 0; currTarget <= target; currTarget++) {
                bool notTake = prev[currTarget];
                bool take = false; 
                if (currTarget >= nums[index]) {
                    take = prev[currTarget - nums[index]];
                }

                curr[currTarget] = notTake || take;
            }
            prev = curr;
        }

        return prev[target];
    }
};