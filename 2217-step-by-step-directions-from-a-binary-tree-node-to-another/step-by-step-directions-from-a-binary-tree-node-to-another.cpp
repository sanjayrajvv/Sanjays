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
    TreeNode *lowestCommonAncestor(TreeNode *root, int p, int q) {
		//Base case
        if (root == NULL || root->val == p || root->val == q) {
            return root;
        }

        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);

        //while coming back
        if (l == NULL) {
            return r;
        } else if (r == NULL) {
            return l;
        } else {
            return root;//if both are not null
        }
    }

    bool dfs(TreeNode *node, int x, string &path, bool rev = false) {
        if (node == NULL) return false;
        if (node->val == x) return true;

        if (rev) path += 'U';
        else path += 'L';
        if (dfs(node->left, x, path, rev)) return true;
        path.pop_back();

        if (rev) path += 'U';
        else path += 'R';
        if (dfs(node->right, x, path, rev)) return true;
        path.pop_back();

        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *lca = lowestCommonAncestor(root, startValue, destValue);

        string pathFrom = "", pathTo = "";
        dfs(lca, startValue, pathFrom, 1);
        dfs(lca, destValue, pathTo);

        return pathFrom + pathTo;
    }
};