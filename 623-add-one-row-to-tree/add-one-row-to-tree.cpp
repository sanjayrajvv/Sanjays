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
    TreeNode *helper(TreeNode *root, int val, int depth, int currDepth) {
        if (depth == 1) {
            return new TreeNode(val, root, NULL);
        }

        if (!root) return root;

        if (currDepth == depth - 1) {
            TreeNode *l = root->left;
            TreeNode *r = root->right;

            root->left = new TreeNode(val, l, NULL);

            root->right = new TreeNode(val, NULL, r);

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