class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        backtrack(0, target, candidates, ds, ans);

        return ans;        
    }

private:
    void backtrack(int index, int target, vector<int>& candidates, vector<int>& ds, 
                    vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        if (index == candidates.size() || target < 0) {
            return;
        }

        ds.push_back(candidates[index]);
        backtrack(index, target - candidates[index], candidates, ds, ans);

        ds.pop_back();
        backtrack(index + 1, target, candidates, ds, ans);
    }
};