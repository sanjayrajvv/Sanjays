class Solution {
    int countPaths(TreeNode* root, int target, std::vector<int>& path) {
        if (!root) return 0;

        path.push_back(root->val);
        long sum = 0, counter = 0;

        for (int i = path.size() - 1; i >= 0; --i) {
            sum += path[i];
            if (sum == target) {
                counter++;
            }
        }

        counter += countPaths(root->left, target, path);
        counter += countPaths(root->right, target, path);

        path.pop_back();
        return counter;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        std::vector<int> path;
        return countPaths(root, targetSum, path);
    }
};
