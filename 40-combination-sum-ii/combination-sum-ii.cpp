class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        sort(candidates.begin(), candidates.end());

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

        for (int i = index; i < candidates.size(); i++) {
            if (i != index && candidates[i - 1] == candidates[i]) continue;
            if (candidates[i] > target) return;

            ds.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], candidates, ds, ans);

            ds.pop_back();
        }
    }
};