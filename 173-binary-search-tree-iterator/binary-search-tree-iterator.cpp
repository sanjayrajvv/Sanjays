class BSTIterator {
private:
    stack<TreeNode*> st;

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* top = st.top();
        st.pop();

        pushAll(top->right);

        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

private:
    void pushAll(TreeNode* root) {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }
};
