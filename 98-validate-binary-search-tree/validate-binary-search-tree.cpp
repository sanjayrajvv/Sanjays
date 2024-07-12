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
    bool f(TreeNode *root, long leftMin, long rightMax) {
        if (root == NULL) return true;
        
        if (leftMin >= root->val || root->val >= rightMax) {
            return false;
        }

        return f(root->left, leftMin, root->val) && f(root->right, root->val, rightMax);
    }
public:
    bool isValidBST(TreeNode* root) {
        return f(root, LONG_MIN, LONG_MAX);
    }
};