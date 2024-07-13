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
    TreeNode *findRightMost(TreeNode *root) {
        while (root->right != NULL) {
            root = root->right;
        }

        return root;
    }
    TreeNode *deleteHelper(TreeNode *root) {
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        TreeNode *rightChild = root->right;
        TreeNode *lastRight = findRightMost(root->left);
        lastRight->right = rightChild;

        return root->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        if (root->val == key) return deleteHelper(root);

        TreeNode *dummy = root;

        while (root != NULL) {
            if (key < root->val) {
                if (root->left && root->left->val == key) {
                    root->left = deleteHelper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right && root->right->val == key) {
                    root->right = deleteHelper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }

        return dummy;
    }
};