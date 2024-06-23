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
    TreeNode *helper(TreeNode* root, int val, int depth, int currDepth) {
        if (depth == 1) {
            TreeNode *node = new TreeNode(val);
            node->left = root;
            node->right = NULL;

            return node;
        }

        if (root == NULL) return root;

        if (currDepth == depth - 1) {
            TreeNode *leftman = root->left;
            TreeNode *rightman = root->right;

            root->left = new TreeNode(val);
            root->left->left = leftman;
            root->left->right = NULL;

            root->right = new TreeNode(val);
            root->right->left = NULL;
            root->right->right = rightman;

            return root;
        }

        root->left = helper(root->left, val, depth, currDepth + 1);
        root->right = helper(root->right, val, depth, currDepth + 1); 

        return root;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return helper(root, val, depth, 1);
    }
};