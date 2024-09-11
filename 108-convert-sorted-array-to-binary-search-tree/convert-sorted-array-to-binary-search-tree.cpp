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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        return createBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* createBST(vector<int>& nums, int l, int h) {
        if (l > h) {
            return nullptr;
        }

        int mid = (l + h) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = createBST(nums, l, mid - 1);
        root->right = createBST(nums, mid + 1, h);

        return root;
    }
};