class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});

        while (!q.empty()) {
            int size = q.size();

            TreeNode* parent1 = nullptr;
            TreeNode* parent2 = nullptr;
            for (int i = 0; i < size; i++) {
                auto [node, parent] = q.front();
                q.pop();

                if (node->val == x) {
                    parent1 = parent;
                }

                if (node->val == y) {
                    parent2 = parent;
                }

                if (node->left) {
                    q.push({node->left, node});
                }
                if (node->right) {
                    q.push({node->right, node});
                }
            }

            if (parent1 && parent2) {
                return parent1 != parent2; 
            }

            if ((parent1 && !parent2) || (!parent1 && parent2)) {
                return false; 
            }
        }

        return false;
    }
};
