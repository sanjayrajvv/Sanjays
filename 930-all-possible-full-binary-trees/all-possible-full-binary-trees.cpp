class Solution {
private:
    unordered_map<int, vector<TreeNode*>> dp;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if ((n % 2) == 0) {
            return {};
        }

        if (n == 1) {
            return {new TreeNode()};
        }

        if (dp.find(n) != dp.end()) {
            return dp[n];
        }

        vector<TreeNode*> res;
        for (int i = 0; i < n; i++) {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n - i - 1);

            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* root = new TreeNode(0, l, r);

                    res.push_back(root);
                }
            }
        }

        return dp[n] = res;
    }
};