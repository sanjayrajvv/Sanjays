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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* node = root;

        root = dfs(node, target);

        return root;
    }

private:
    TreeNode* dfs(TreeNode* node, int target) {
        if (node == nullptr) {
            return nullptr;
        }


        node->left = dfs(node->left, target);
        node->right = dfs(node->right, target);

        if (node->left == nullptr && node->right == nullptr && node->val == target) {
            return nullptr;
        }

        return node;
    }
};