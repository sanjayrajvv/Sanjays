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
private:
    TreeNode *leftMost(TreeNode *node) {
        while (node->right) {
            node = node->right;
        }

        return node;
    }
public:
    void flatten(TreeNode* root) {
        if (root == NULL) return;

        while (root) {
            if (!root->left) {
                root = root->right;
            } else {
                TreeNode *rightMost = leftMost(root->left);
                TreeNode *temp = root->right;
                root->right = root->left;
                root->left = NULL;
                rightMost->right = temp;
                root = root->right;
            }
        }
    }
};