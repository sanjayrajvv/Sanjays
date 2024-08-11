/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> dp;

        return allPossibleBST(1, n, dp);
    }

private:
    vector<TreeNode*> allPossibleBST(int start, int end, 
                                    map<pair<int, int>, vector<TreeNode*>> &dp) {
        vector<TreeNode*> res;

        if (start > end) {
            res.push_back(nullptr);
        }

        if (dp.find(make_pair(start, end)) != dp.end()) {
            return dp[make_pair(start, end)];
        }

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftSubtrees = allPossibleBST(start, i - 1, dp);
            vector<TreeNode*> rightSubtrees = allPossibleBST(i + 1, end, dp);

            for (auto left : leftSubtrees) {
                for (auto right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i, left, right);
                    res.push_back(root);
                }
            }
        }

        return dp[make_pair(start, end)] = res;
    }
};