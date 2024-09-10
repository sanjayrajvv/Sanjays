class Solution {
private:
    TreeNode* firstNode;
    TreeNode* prevNode;
    TreeNode* middleNode;
    TreeNode* secondNode;

public:
    void recoverTree(TreeNode* root) {
        firstNode = nullptr;
        middleNode = nullptr;
        secondNode = nullptr;
        prevNode = new TreeNode(INT_MIN);
        
        inorder(root);

        if (secondNode != nullptr) {
            swap(firstNode->val, secondNode->val);
        } else {
            swap(firstNode->val, middleNode->val);
        }
    }

private:
    void inorder(TreeNode* root) {
        if (root != nullptr) {
            inorder(root->left);

            if (root->val < prevNode->val) {
                if (firstNode == nullptr) {
                    firstNode = prevNode;
                    middleNode = root;
                } else {
                    secondNode = root;
                }
            } 

            prevNode = root;
            inorder(root->right);
        }
    }
};