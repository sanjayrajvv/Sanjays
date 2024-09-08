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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;

        dfs(root, maxi);

        return maxi;
    }

private:
    int dfs(TreeNode* node, int& maxi) {
        if (node == nullptr) return 0;

        int l = max(0, dfs(node->left, maxi));
        int r = max(0, dfs(node->right, maxi));

        maxi = max(maxi, node->val + l + r);

        return (node->val) + max(l, r);
    }
};