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
    void inorder(TreeNode* root, vector<int> &list) {
        if (root) {
            inorder(root->left, list);
            if (!root->left && !root->right) list.push_back(root->val);
            inorder(root->right, list);
        } 
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> list1, list2;

        inorder(root1, list1);
        inorder(root2, list2);

        return list1 == list2;
    }
};