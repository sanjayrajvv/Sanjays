class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            int minIndex = q.front().second;
            int first, last;

            for (int i = 1; i <= size; i++) {
                long long curr_id = q.front().second - minIndex;
                TreeNode *node = q.front().first;
                q.pop();

                if (i == 1) {
                    first = curr_id;
                } 
                
                if (i == size) {
                    last = curr_id;
                }

                if (node->left) {
                    q.push({node->left, curr_id * 2 + 1});
                }

                if (node->right) {
                    q.push({node->right, curr_id * 2 + 2});
                }
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};