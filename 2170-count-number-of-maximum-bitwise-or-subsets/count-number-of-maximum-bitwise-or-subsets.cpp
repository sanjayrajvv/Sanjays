class Solution {
private:
    int f(int i, int currOr, int target, vector<int>& nums) {
        if (i == nums.size()) {
            return currOr == target;
        }

        int notPick = f(i + 1, currOr, target, nums);
        int pick = f(i + 1, currOr | nums[i], target, nums);

        return notPick + pick;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        for (int i = 0; i < nums.size(); i++) {
            target |= nums[i];
        }

        return f(0, 0, target, nums);
    }
};