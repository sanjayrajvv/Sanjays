class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return symmetric(root->left, root->right);       
    }

private:
    bool symmetric(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        } else if (p->val != q->val) {
            return false;
        }

        return symmetric(p->left, q->right) && symmetric(p->right, q->left);
    }
};