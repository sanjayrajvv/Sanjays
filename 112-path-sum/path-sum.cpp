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
    bool checkSum(TreeNode *root, int target) {
        if (root == NULL) return false;

        if (!root->left && !root->right) {
            if (target - root->val == 0) return true;
        }

        if (checkSum(root->left, target - root->val) == true || checkSum(root->right, target - root->val) == true) {
            return true;
        }

        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return checkSum(root, targetSum);
    }
};