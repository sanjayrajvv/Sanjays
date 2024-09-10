class Solution {
public:
    void root_to_leaf(TreeNode *root, vector<string> &ans, string path) {
        if (root == nullptr) {
            return;
        }

        path += to_string(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
            return;
        } else {
            path += "->";

            root_to_leaf(root->left, ans, path);
            root_to_leaf(root->right, ans, path);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path;

        root_to_leaf(root, ans, path);

        return ans;
    }
};