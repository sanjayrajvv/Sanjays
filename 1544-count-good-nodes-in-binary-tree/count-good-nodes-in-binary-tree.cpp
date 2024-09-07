class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }

private:
    int dfs(TreeNode* node, int maxVal) {
        if (!node) return 0;

        int count = (node->val >= maxVal) ? 1 : 0;
        maxVal = max(maxVal, node->val);

        return count + dfs(node->left, maxVal) + dfs(node->right, maxVal);
    }
};
