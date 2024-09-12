class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        unordered_map<int, bool> taken;

        backtrack(nums, ds, ans, taken);

        return ans;
    }

private:
    void backtrack(vector<int>& nums, vector<int>& ds, 
                    vector<vector<int>>& ans, unordered_map<int, bool>& taken) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (taken[i] == false) {
                taken[i] = true;
                ds.push_back(nums[i]);
                backtrack(nums, ds, ans, taken);

                taken[i] = false;
                ds.pop_back(); 
            }
        }
    }
};