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
    int f(TreeNode *root, int &maxPath) {
        if (root == NULL) return 0;

        int l = max(0, f(root->left, maxPath));
        int r = max(0, f(root->right, maxPath));

        maxPath = max(maxPath, root->val + l + r);

        return root->val + max(l, r);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;

        f(root, maxPath);

        return maxPath;
    }
};