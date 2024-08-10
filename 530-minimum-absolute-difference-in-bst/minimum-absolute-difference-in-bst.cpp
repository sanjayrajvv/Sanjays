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
    int getMinimumDifference(TreeNode* root) {
        int mini = INT_MAX;
        TreeNode* prev = nullptr;

        inOrderTraversal(root, prev, mini);
        
        return mini;
    }
    
private:
    void inOrderTraversal(TreeNode* node, TreeNode*& prev, int& mini) {
        if (!node) return;
        
        inOrderTraversal(node->left, prev, mini);
        
        if (prev != nullptr) {
            mini = min(mini, abs(node->val - prev->val));
        }
        prev = node;
        
        inOrderTraversal(node->right, prev, mini);
    }
};
