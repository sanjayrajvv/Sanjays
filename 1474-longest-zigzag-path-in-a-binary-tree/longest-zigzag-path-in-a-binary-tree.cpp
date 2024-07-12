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
    int longestZigZagHelper(TreeNode* root, int direction, int length, int& longest) {
        if (root == nullptr) return 0;

        longest = max(longest, length);
        
        if (direction == 0) {
            // Last move was to the left, so move to the right next
            longestZigZagHelper(root->left, 1, length + 1, longest);
            longestZigZagHelper(root->right, 0, 1, longest);
        } else {
            // Last move was to the right, so move to the left next
            longestZigZagHelper(root->right, 0, length + 1, longest);
            longestZigZagHelper(root->left, 1, 1, longest);
        }

        return longest;
    }
public:
    int longestZigZag(TreeNode* root) {
        if (root == nullptr) return 0;

        int longest = 0;
        longestZigZagHelper(root, 0, 0, longest);
        longestZigZagHelper(root, 1, 0, longest);

        return longest;
    }
};
