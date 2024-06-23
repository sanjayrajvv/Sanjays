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
class BSTIterator {
    stack<TreeNode*> S;
    bool reverse = true;

    void pushAll(TreeNode *root) {
        while (root != NULL) {
            S.push(root);
            if (reverse) root = root->left;
            else root = root->right;
        }
    }
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode *temp = S.top();
        S.pop();

        if (reverse) pushAll(temp->right);
        else pushAll(temp->left);

        return temp->val;
    }
    
    bool hasNext() {
		return !S.empty();  
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator front(root, true);
        BSTIterator back(root, false);

        int l = front.next();
        int h = back.next();

        while (l < h) {
            if (l + h == k) return true;
            else if (l + h > k) h = back.next();
            else l = front.next();
        }

        return false;
    }
};