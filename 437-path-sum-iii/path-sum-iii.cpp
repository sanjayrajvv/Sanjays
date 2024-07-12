class Solution {
    void findPaths(TreeNode* root, int targetSum, unordered_map<long, int>& prefixSumCount, long currentSum, int &count) {
        if (!root) return;

        currentSum += root->val;

        if (currentSum == targetSum) count++;

        count += prefixSumCount[currentSum - targetSum];

        prefixSumCount[currentSum]++;

        findPaths(root->left, targetSum, prefixSumCount, currentSum, count);
        findPaths(root->right, targetSum, prefixSumCount, currentSum, count);

        prefixSumCount[currentSum]--;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> prefixSumCount;
        int count = 0;
        findPaths(root, targetSum, prefixSumCount, 0, count);
        return count;
    }
};
