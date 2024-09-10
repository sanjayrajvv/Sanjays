class Solution {
private:
    int index;

public:
    // O(2n + nlogn)
    void recoverTree(TreeNode* root) {
        vector<int> inorderList;
        inorder(root, inorderList); //O(n)

        sort(inorderList.begin(), inorderList.end()); //O(nlogn)

        index = 0;
        recover(root, inorderList); // O(n)
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