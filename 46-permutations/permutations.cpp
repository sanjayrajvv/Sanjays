class Solution {
private:
    void f(int index, vector<int> &nums, vector<vector<int>> &ans) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            f(index + 1, nums, ans);
            swap(nums[i], nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        f(0, nums, ans);

        return ans;
    }
};