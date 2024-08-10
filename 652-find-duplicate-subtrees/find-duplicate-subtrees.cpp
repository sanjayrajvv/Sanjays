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
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> duplicates;
        unordered_map<string, vector<TreeNode*>> subtrees;

        dfs(root, subtrees, duplicates);

        return duplicates;
    }

private:
    string dfs(TreeNode *node, unordered_map<string, 
                vector<TreeNode*>>& subtrees, vector<TreeNode*>& duplicates) {
        if (!node) {
            return "";
        }

        string s = to_string(node->val) + "," 
                + dfs(node->left, subtrees, duplicates) + ","
                + dfs(node->right, subtrees, duplicates);
        
        if (subtrees[s].size() == 1) {
            duplicates.push_back(node);
        }
        subtrees[s].push_back(node);

        return s;
    }
};