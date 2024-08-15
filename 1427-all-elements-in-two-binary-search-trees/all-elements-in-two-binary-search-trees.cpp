class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

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
};

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        BSTIterator it1(root1), it2(root2);

        int num1 = it1.hasNext() ? it1.next() : INT_MAX;
        int num2 = it2.hasNext() ? it2.next() : INT_MAX;

        while (num1 != INT_MAX || num2 != INT_MAX) {
            if (num1 < num2) {
                ans.push_back(num1);
                num1 = it1.hasNext() ? it1.next() : INT_MAX;
            } else {
                ans.push_back(num2);
                num2 = it2.hasNext() ? it2.next() : INT_MAX;
            }
        }

        return ans;
    }
};
