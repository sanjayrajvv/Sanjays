class Solution {
public:
    int rob(TreeNode* root) {
        pair<int, int> collection = dfs(root);

        return max(collection.first, collection.second);
    }

private:
    pair<int, int> dfs(TreeNode *root) {
        if (root == NULL) {
            return {0, 0};
        }

        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        pair<int, int> ans;
        int take = root->val + left.second + right.second;
        int notTake = max(left.first, left.second) + max(right.first, right.second);

        ans = make_pair(take, notTake);

        return ans;
    }
};