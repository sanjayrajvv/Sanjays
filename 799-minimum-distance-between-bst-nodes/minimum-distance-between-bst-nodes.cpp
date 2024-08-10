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
    int minDiff = INT_MAX;
public:
    int minDiffInBST(TreeNode* root) {
        TreeNode* prev = NULL;
        inorder(root, prev);

        return minDiff;
    }

private:
    void inorder(TreeNode *node, TreeNode *&prev) {
        if (!node) return;

        inorder(node->left, prev);

        if (prev != NULL) {
            minDiff = min(minDiff, node->val - prev->val);
        }
        prev = node;

        inorder(node->right, prev);
    }
};