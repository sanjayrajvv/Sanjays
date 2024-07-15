class Solution {
private:
    void f(int n, vector<int> &nums, map<int, bool> &mp,
    vector<vector<int>> &ans, vector<int> &ds) {
        if (ds.size() == n) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (mp[i] != 1) {
                ds.push_back(nums[i]);
                mp[i] = 1;
                f(n, nums, mp, ans, ds);
                ds.pop_back();
                mp[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        map<int, bool> mp;

        f(n, nums, mp, ans, ds);

        return ans;
    }
};