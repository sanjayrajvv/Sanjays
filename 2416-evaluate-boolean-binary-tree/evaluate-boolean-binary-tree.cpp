class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (!root->left && !root->right) {
            if (root->val == 0) return false;
            if (root->val == 1) return true;
        }

        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);

        if (root->val == 2) {
            return left | right;
        } else {
            return left && right;
        }
    }
};