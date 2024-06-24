class Solution {
    void f(vector<int> &nums, map<int, int> &m, vector<int> &ds, vector<vector<int>> &ans) {
        for (int i = 0; i < nums.size(); i++) {
            if (ds.size() == nums.size()) {
                ans.push_back(ds);
                return;
            }

            if (m[nums[i]] == 0) {
                ds.push_back(nums[i]);
                m[nums[i]] = 1;
                f(nums, m, ds, ans);

                ds.pop_back();
                m[nums[i]] = 0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        map<int, int> m;

        for (int i = 0; i < nums.size(); i++) m[nums[i]] = 0;

        f(nums, m, ds, ans);

        return ans;
    }
};