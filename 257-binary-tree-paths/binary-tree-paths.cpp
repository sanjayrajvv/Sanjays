class Solution {
public:
    void root_to_leaf(TreeNode *root, vector<string> &ans, string path) {
        
        if (root == nullptr) {
            return;
        }

        path += to_string(root->val) + "->";

        if (root->left == nullptr && root->right == nullptr) {
            //path += to_string(root->val);
            path.pop_back();
            path.pop_back();
            
            ans.push_back(path);

            return;
        }

        //path.push_back(root->val);
        root_to_leaf(root->left, ans, path);
        root_to_leaf(root->right, ans, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path;

        root_to_leaf(root, ans, path);

        return ans;
    }
};