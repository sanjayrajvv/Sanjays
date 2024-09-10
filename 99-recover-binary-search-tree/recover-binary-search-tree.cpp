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
private:
    int index;

public:
    void recoverTree(TreeNode* root) {
        vector<int> inorderList;
        inorder(root, inorderList);

        sort(inorderList.begin(), inorderList.end());

        index = 0;
        recover(root, inorderList);
    }

private:
    void inorder(TreeNode* root, vector<int>& inorderList) {
        if (root != nullptr) {
            inorder(root->left, inorderList);
            inorderList.push_back(root->val);
            inorder(root->right, inorderList);
        }
    }

    void recover(TreeNode* root, vector<int>& inorderList) {
        if (root != nullptr) {
            recover(root->left, inorderList);
            root->val = inorderList[index];
            index++;
            recover(root->right, inorderList);
        }
    }
};