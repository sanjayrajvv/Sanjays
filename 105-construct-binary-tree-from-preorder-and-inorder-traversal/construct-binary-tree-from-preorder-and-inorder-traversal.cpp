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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return build(0, n - 1, preorder, 0, n - 1, inorder);
    }

private:
    TreeNode* build(int preStart, int preEnd, vector<int>& preorder, 
                    int inStart, int inEnd, vector<int>& inorder) {
        if (preStart > preEnd || inStart > inEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = findIndex(preorder[preStart], inorder);
        int numsLeft = inRoot - inStart;

        root->left = build(preStart + 1, preStart + numsLeft, preorder, 
                          inStart, inRoot - 1, inorder);
        root->right = build(preStart + numsLeft + 1, preEnd, preorder, 
                            inRoot + 1, inEnd, inorder);
        
        return root;
    }

    int findIndex(int e, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == e) {
                return i;
            }
        }

        return -1;
    }
};