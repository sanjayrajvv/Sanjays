class Solution {
    void f(int index, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans) {
        if (index == nums.size()) {
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[index]);
        f(index + 1, nums, ds, ans);
        ds.pop_back();
        f(index + 1, nums, ds, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;

        f(0, nums, ds, ans);

        return ans;
    }
};