class Solution {
private:
    void f(int n, vector<int>& nums, vector<bool>& used,
           vector<vector<int>>& ans, vector<int>& ds) {
        if (ds.size() == n) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < n; i++) {
            // Skip used elements or duplicates
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
                continue;
            }
            
            // Mark the element as used
            used[i] = true;
            ds.push_back(nums[i]);

            // Recurse
            f(n, nums, used, ans, ds);

            // Backtrack
            used[i] = false;
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> used(nums.size(), false);

        // Sort to handle duplicates
        sort(nums.begin(), nums.end());

        // Start the recursive function
        f(nums.size(), nums, used, ans, ds);

        return ans;
    }
};
