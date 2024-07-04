class Solution {
    void f(int index, int n, int k, vector<int> &nums, vector<int> &ds, 
    vector<vector<int>> &ans) {
        if (ds.size() == k) {
            ans.push_back(ds);
            return;
        }

        if (index == n) {
            return;
        }

        ds.push_back(nums[index]);
        f(index + 1, n, k, nums, ds, ans);
        ds.pop_back();
        f(index + 1, n, k, nums, ds, ans);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        vector<vector<int>> ans;
        vector<int> ds;

        f(0, n, k, nums, ds, ans);

        return ans;
    }
};