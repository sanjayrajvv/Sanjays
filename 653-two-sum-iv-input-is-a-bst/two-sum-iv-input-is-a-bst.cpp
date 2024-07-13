class BSTIterator {
private:
    stack<TreeNode*> st;
    bool reverse = true;

private:
    void pushAll(TreeNode *root) {
        while (root) {
            st.push(root);

            if (reverse) root = root->right;
            else root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
        
    }
    
    int next() {
        TreeNode *top = st.top();
        st.pop();

        if (reverse) pushAll(top->left);
        else pushAll(top->right);

        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator l = BSTIterator(root, false);
        BSTIterator r = BSTIterator(root, true);

        int i = l.next();
        int j = r.next();

        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) i = l.next();
            else j = r.next();
        }

        return false;
    }
};